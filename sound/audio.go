package main

// #cgo amd64 386 CFLAGS: -g -Wall
// #cgo LDFLAGS: -L. -lpulse -lc
// #include "stdio.h"
// #include "dde-pulse.h"
import "C"

import (
	"dlib/dbus"
	"fmt"
	"os"
	"strconv"
	"unsafe"
)

type Audio struct {
	NumDevics int32
	pa        *C.pa
	HostName  string
	UserName  string
	//Change func(int32)
}

type Sink struct {
	Index        int32
	Name         string
	Description  string
	Driver       string
	Mute         string
	NVolumeSteps int32
	Card         int32
	Cvolume      Volume
}

//Only capitalized first character in Capitalized structure can be exposed

type Source struct {
	Index        int32
	Name         string
	Description  string
	Driver       string
	Mute         int32
	NVolumeSteps int32
	Card         int32
	C_ports      int32
	N_formates   int32
	Cvolume      Volume
}

type SinkInput struct {
	Index           int32
	Name            string
	Owner_module    int32
	Client          int32
	Sink            int32
	Cvolume         Volume
	Driver          string
	Mute            int32
	Has_volume      int32
	Volume_writable int32
}

type SourceOutput struct {
	Index           int32
	Name            string
	Owner_module    int32
	Client          int32
	Source          int32
	Cvolume         Volume
	Driver          string
	Mute            int32
	Has_volume      int32
	Volume_writable int32
}

type Client struct {
	Index        int32
	Name         string
	Owner_module int32
	Driver       string
	//pa_proplist *proplist
	Prop map[string]string
}

type Card struct {
	Index        int32
	Name         string
	Owner_module int32
	Driver       string
}

type Volume struct {
	Channels uint32
	Values   [320]uint32
}

func NewAudio() (*Audio, error) {
	audio := Audio{}
	audio.pa = C.pa_new()
	if audio.pa == nil {
		fmt.Fprintln(os.Stderr,
			"unable to connect to the pulseaudio server,exiting\n")
		os.Exit(-1)
	}
	fmt.Println("module started\n")
	return &audio, nil
}

func (o *Audio) GetDBusInfo() dbus.DBusInfo {
	return dbus.DBusInfo{
		"com.deepin.daemon.Audio",
		"/com/deepin/daemon/Audio",
		"com.deepin.daemon.Audio",
	}
}

func (audio *Audio) GetServerInfo() *Audio {
	C.pa_get_server_info(audio.pa)
	audio.HostName = C.GoString(audio.pa.server_info.host_name)
	audio.UserName = C.GoString(audio.pa.server_info.user_name)
	//fmt.Print("go: " + audio.HostName + "\n")
	fmt.Print("go: " + C.GoString((audio.pa.server_info.host_name)) + "\n")

	return audio
}

func (audio *Audio) GetCards() []*Card {
	C.pa_get_card_list(audio.pa)
	n := int(audio.pa.n_cards)
	cards := make([]*Card, n)
	for i := 0; i < n; {
		cards[i] = &Card{}
		cards[i].Index = int32(audio.pa.cards[i].index)
		cards[i].Name = C.GoString(&audio.pa.cards[i].name[0])
		cards[i].Driver = C.GoString(&audio.pa.cards[i].driver[0])
		cards[i].Owner_module = int32(audio.pa.cards[i].owner_module)
		i = i + 1
	}
	return cards
}

func (audio *Audio) GetSinks() []*Sink {
	C.pa_get_device_list(audio.pa)
	n := int(audio.pa.n_sinks)
	sinks := make([]*Sink, n)
	for i := 0; i < 1; i = i + 1 {
		sinks[i] = &Sink{}
		sinks[i].Index = int32(audio.pa.sinks[i].index)
		sinks[i].Card = int32(audio.pa.sinks[i].card)
		sinks[i].Description =
			C.GoString((*C.char)(unsafe.Pointer(&audio.pa.sinks[i].description[0])))
		sinks[i].Driver = C.GoString(&audio.pa.sinks[i].driver[0])
		sinks[i].Name = C.GoString(&audio.pa.sinks[i].name[0])
		sinks[i].Cvolume.Channels = uint32(audio.pa.sinks[i].volume.channels)
		for j := 0; j < int(sinks[i].Cvolume.Channels); j = j + 1 {
			sinks[i].Cvolume.Values[j] =
				*((*uint32)(unsafe.Pointer(&audio.pa.sinks[i].volume.values[j])))
		}
		fmt.Println("Index: " + strconv.Itoa(int((sinks[i].Index))) + " Card:" + strconv.Itoa(int(sinks[i].Card)))
	}

	return sinks
}

func (audio *Audio) GetSources() []*Source {
	C.pa_get_device_list(audio.pa)
	n := int(audio.pa.n_sources)
	sources := make([]*Source, n)

	for i := 0; i < n; i = i + 1 {
		sources[i] = &Source{}
		sources[i].Index = int32(audio.pa.sources[i].index)
		sources[i].Card = int32(audio.pa.sources[i].card)
		sources[i].Mute = int32(audio.pa.sources[i].mute)
		sources[i].Name = C.GoString((*C.char)(unsafe.Pointer(&audio.pa.sources[i].name[0])))
		sources[i].Description = C.GoString(&audio.pa.sources[i].description[0])

		sources[i].Cvolume.Channels = uint32(audio.pa.sources[i].volume.channels)
		for j := uint32(0); j < sources[i].Cvolume.Channels; j = j + 1 {
			sources[i].Cvolume.Values[j] =
				*((*uint32)(unsafe.Pointer(&audio.pa.sources[i].volume.values[j])))
		}
	}
	return sources
}

func (audio *Audio) GetSinkInputs() []*SinkInput {
	C.pa_get_sink_input_list(audio.pa)
	n := int(audio.pa.n_sink_inputs)
	sinkInputs := make([]*SinkInput, n)

	fmt.Fprint(os.Stderr, audio.pa.sink_inputs[0].index)

	for i := 0; i < n; i = i + 1 {
		sinkInputs[i] = &SinkInput{}
		sinkInputs[i].Index = int32(audio.pa.sink_inputs[i].index)
		sinkInputs[i].Client = int32(audio.pa.sink_inputs[i].client)
		sinkInputs[i].Sink = int32(audio.pa.sink_inputs[i].sink)
		sinkInputs[i].Mute = int32(audio.pa.sink_inputs[i].mute)
		sinkInputs[i].Has_volume = int32(audio.pa.sink_inputs[i].has_volume)
		sinkInputs[i].Volume_writable = int32(audio.pa.sink_inputs[i].volume_writable)
		sinkInputs[i].Cvolume.Channels = uint32(audio.pa.sink_inputs[i].volume.channels)
		for j := uint32(0); j < sinkInputs[i].Cvolume.Channels; j = j + 1 {
			sinkInputs[i].Cvolume.Values[j] =
				*(*uint32)(unsafe.Pointer(&audio.pa.sink_inputs[i].volume.values[j]))
		}
	}
	return sinkInputs
}

func (audio *Audio) GetSourceOutputs() []*SourceOutput {
	C.pa_get_source_output_list(audio.pa)
	n := int(audio.pa.n_source_outputs)
	var sourceOutputs = make([]*SourceOutput, n)

	fmt.Print(len(sourceOutputs))
	/*if n < 0 {
		return nil
	}*/

	for i := 0; i < n; i = i + 1 {
		sourceOutputs[i] = &SourceOutput{}
		sourceOutputs[i].Index = int32(audio.pa.source_outputs[i].index)
		sourceOutputs[i].Name = C.GoString(&audio.pa.source_outputs[i].name[0])
		sourceOutputs[i].Owner_module = int32(audio.pa.source_outputs[i].owner_module)
		sourceOutputs[i].Client = int32(audio.pa.source_outputs[i].client)
		sourceOutputs[i].Source = int32(audio.pa.source_outputs[i].source)
		sourceOutputs[i].Driver = C.GoString(&audio.pa.source_outputs[i].driver[0])
		sourceOutputs[i].Mute = int32(audio.pa.source_outputs[i].mute)
		sourceOutputs[i].Cvolume.Channels = uint32(audio.pa.source_outputs[i].volume.channels)

		for j := uint32(0); j < sourceOutputs[i].Cvolume.Channels; j = j + 1 {
			sourceOutputs[i].Cvolume.Values[j] =
				*((*uint32)(unsafe.Pointer(&audio.pa.source_outputs[i].volume.values[j])))
		}
	}
	return sourceOutputs
}

func (audio *Audio) GetClients() []*Client {
	C.pa_get_client_list(audio.pa)
	n := int(audio.pa.n_clients)
	var clients = make([]*Client, n)

	for i := 0; i < n; i = i + 1 {
		clients[i] = &Client{}
		clients[i].Index = int32(audio.pa.clients[i].index)
		clients[i].Owner_module = int32(audio.pa.clients[i].owner_module)
		clients[i].Name = C.GoString((*C.char)(unsafe.Pointer(&audio.pa.clients[i].name[0])))
		clients[i].Driver = C.GoString((*C.char)(unsafe.Pointer(&audio.pa.clients[i].driver[0])))
	}
	return clients
}

func (sink *Sink) GetDBusInfo() dbus.DBusInfo {
	return dbus.DBusInfo{
		"com.deepin.daemon.Audio",
		"/com/deepin/daemon/Audio/Output" + strconv.FormatInt(int64(sink.Index), 10),
		"com.deepin.daemon.Audio.Output",
	}
}

func (sink *Sink) GetSinkVolume() Volume {
	return sink.Cvolume
}

func (sink *Sink) SetSinkVolume(volume Volume) int32 {
	var cvolume C.pa_cvolume
	cvolume.channels = C.uint8_t(volume.Channels)
	for i := uint32(0); i < volume.Channels; i = i + 1 {
		cvolume.values[i] = *((*C.pa_volume_t)(unsafe.Pointer(&volume.Values[i])))
	}
	return int32(C.pa_set_sink_volume_by_index(
		audio.pa, C.int(sink.Index), &cvolume))
}

func (sink *Sink) SetSinkVolumeInt(volume int32) int32 {
	var cvolume C.pa_cvolume
	cvolume.channels = C.uint8_t(2)
	for i := 0; i < 2; i = i + 1 {
		cvolume.values[i] = C.pa_volume_t(volume)
	}
	return int32(C.pa_set_sink_volume_by_index(
		audio.pa, C.int(sink.Index), &cvolume))
}

func (sink *Sink) SetSinkMute(mute int32) int32 {
	ret := C.pa_set_sink_mute_by_index(
		audio.pa, C.int(sink.Index), C.int(mute))
	return int32(ret)
}

func (source *Source) GetDBusInfo() dbus.DBusInfo {
	return dbus.DBusInfo{
		"com.deepin.daemon.Audio",
		"/com/deepin/daemon/Audio/Input" + strconv.FormatInt(int64(source.Index), 10),
		"com.deepin.daemon.Audio.Input",
	}
}

func (source *Source) GetSourceVolume() Volume {
	return source.Cvolume
}

func (source *Source) SetSourceVolume(volume Volume) int32 {
	var cvolume C.pa_cvolume
	cvolume.channels = C.uint8_t(volume.Channels)
	for i := uint32(0); i < volume.Channels; i = i + 1 {
		cvolume.values[i] =
			*((*C.pa_volume_t)(unsafe.Pointer(&volume.Values[i])))
	}
	return int32(C.pa_set_source_volume_by_index(
		audio.pa, C.int(source.Index), &cvolume))
}

func (source *Source) SetSourceMute(mute int32) int32 {
	ret := C.pa_set_source_mute_by_index(
		audio.pa, C.int(source.Index), C.int(mute))
	return int32(ret)
}

func (sink_input *SinkInput) GetDBusInfo() dbus.DBusInfo {
	return dbus.DBusInfo{
		"com.deepin.daemon.Audio",
		"/com/deepin/daemon/Audio/Application" + strconv.FormatInt(int64(sink_input.Index), 10),
		"com.deepin.daemon.Audio.Application",
	}
}

func (sink_input *SinkInput) GetSink_input_volume() Volume {
	return Volume{}
}

func (sink_input *SinkInput) SetSink_input_volume(volume Volume) int32 {
	return 1
}

func (sink_input *SinkInput) SetSink_input_mute(mute int32) int32 {
	return 1
}

func (source_output *SourceOutput) GetDBusInfo() dbus.DBusInfo {
	return dbus.DBusInfo{
		"com.deepin.daemon.Audio",
		"/com/deepin/daemon/Audio/Application" + strconv.FormatInt(int64(source_output.Index), 10),
		"com.deepin.daemon.Audio.Application",
	}
}

func (source_output *SourceOutput) GetSource_ouput_volume() Volume {
	return source_output.Cvolume
}

func (source_output *SourceOutput) SetSource_output_volume(volume Volume) Volume {
	return Volume{}
}

func (source_output *SourceOutput) SetSource_output_mute(mute int32) int32 {
	return 1
}

func (client *Client) GetDBusInfo() dbus.DBusInfo {
	return dbus.DBusInfo{
		"com.deepin.daemon.Audio",
		"/com/deepin/daemon/Audio/Client" + strconv.FormatInt(int64(client.Index), 10),
		"com.deepin.daemon.Audio.Client",
	}
}

func (card *Card) GetDBusInfo() dbus.DBusInfo {
	return dbus.DBusInfo{
		"com.deepin.daemon.Card",
		"/com/deepin/daemon/Audio/Card" + strconv.FormatInt(int64(card.Index), 10),
		"com.deepin.daemon.Audio.Card",
	}
}

var audio *Audio

func main() {
	var err error
	audio, err = NewAudio()
	if err != nil {
		panic(err)
		os.Exit(-1)
	}
	dbus.InstallOnSession(audio)
	select {}
}
