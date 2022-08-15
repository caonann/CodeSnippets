package main

import (
	"encoding/json"
	"fmt"
)

type Frame struct {
	SSH   float64 `json:"SSH"`
	AAA   float64 `json:"AAA"`
	AHH   float64 `json:"AHH"`
	EH    float64 `json:"EH"`
	FFF   int     `json:"FFF"`
	GK    float64 `json:"GK"`
	IEE   float64 `json:"IEE"`
	LNTD  float64 `json:"LNTD"`
	MBP   float64 `json:"MBP"`
	OHH   float64 `json:"OHH"`
	RRR   int     `json:"RRR"`
	SCHWA float64 `json:"SCHWA"`
	SSS   float64 `json:"SSS"`
	TTH   float64 `json:"TTH"`
	UUU   float64 `json:"UUU"`
	WWW   float64 `json:"WWW"`
}

func (f Frame) String() string {
	marshal, _ := json.Marshal(f)
	return string(marshal)
}

type SeechRspType struct {
	AlgId      string    `json:"alg_id"`
	AlglibInfo string    `json:"alglib_info"`
	Audio      string    `json:"audio"`
	Autospd    int       `json:"autospd"`
	Codec      string    `json:"codec"`
	ErrMsg     string    `json:"err_msg"`
	ErrNo      int       `json:"err_no"`
	Final      bool      `json:"final"`
	Fps        int       `json:"fps"`
	Language   int       `json:"language"`
	Manspd     int       `json:"manspd"`
	Procspd    int       `json:"procspd"`
	Sampling   int       `json:"sampling"`
	Sessionid  string    `json:"sessionid"`
	ThDim      int       `json:"th_dim"`
	ThFeat     []float64 `json:"th_feat"`
}

type SpeechReqType struct {
	AnimRep struct {
		AlgInfo struct {
			ActionList   []interface{} `json:"action_list"`
			AlglibInfo   string        `json:"alglib_info"`
			AnimCoefList []struct {
				CoefFrame Frame `json:"coef_frame"`
			} `json:"anim_coef_list"`
			CoefType         int     `json:"coef_type"`
			ErrMsg           string  `json:"err_msg"`
			ErrNo            int     `json:"err_no"`
			FirstDelay       float64 `json:"first_delay"`
			FrameCount       int     `json:"frame_count"`
			FrameRate        int     `json:"frame_rate"`
			Language         int     `json:"language"`
			OutputCoefFormat int     `json:"output_coef_format"`
			Rtf              float64 `json:"rtf"`
		} `json:"alg_info"`
		ErrMsg    string `json:"err_msg"`
		ErrNo     int    `json:"err_no"`
		SessionId string `json:"session_id"`
	} `json:"anim_rep"`
	Begin     bool         `json:"begin"`
	End       bool         `json:"end"`
	SpeechRsp SeechRspType `json:"speech_rsp"`
}

type CoeFrame struct {
	CostTime      int           `json:"cost_time"`
	ErrMsg        string        `json:"err_msg"`
	ErrNo         int           `json:"err_no"`
	SessionId     string        `json:"session_id"`
	SpeechRepInfo SpeechReqType `json:"speech_rep_info"`
}

var CoeFrameMap = make(map[string]float32)

func ShowStructSeri() {
	frame := Frame{
		AAA:   0,
		EH:    1,
		FFF:   2,
		GK:    3,
		LNTD:  4,
		AHH:   5,
		MBP:   6,
		OHH:   7,
		RRR:   8,
		SCHWA: 9,
		SSH:   10,
		IEE:   11,
		SSS:   12,
		UUU:   13,
		WWW:   14,
		TTH:   15,
	}
	marshal, _ := json.Marshal(frame)
	fmt.Println(string(marshal))
	frame2 := Frame{}
	err := json.Unmarshal(marshal, &frame2)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println("unmarsh is ", frame2)
}
func ShowMapSeri() {
	CoeFrameMap["AAA"] = 0
	CoeFrameMap["AHH"] = 1
	CoeFrameMap["EH"] = 2
	CoeFrameMap["FFF"] = 3
	CoeFrameMap["GK"] = 4
	CoeFrameMap["IEE"] = 5
	marshal, _ := json.Marshal(CoeFrameMap)
	fmt.Println(string(marshal))
	frame2 := Frame{}
	json.Unmarshal(marshal, &frame2)
	fmt.Println("unmarsh is ", frame2)
}

type FloatTest struct {
	Fnum float32
	Cnum float64
}

func main() {
	ShowMapSeri()
	ShowStructSeri()
	fnum := FloatTest{
		Fnum: 1.03457899991282,
		Cnum: 0.0680000005001,
	}
	b, _ := json.Marshal(fnum)
	fmt.Println(string(b))
}
