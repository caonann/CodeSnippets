package main

import (
	"encoding/json"
	"fmt"
	jsonvalue "github.com/Andrew-M-C/go.jsonvalue"
)

type User struct {
	Id           int    `json:"id"`
	CreatedAt    string `json:"created_at"`
	UpdatedAt    string `json:"updated_at"`
	DeletedAt    string `json:"deleted_at"`
	UserName     string `json:"user_name"`
	Organization string `json:"organization"`
	UserType     int    `json:"user_type"`
}

type TestStructObj struct {
	RetCode   int    `json:"ret_code"`
	RetMsg    string `json:"ret_msg"`
	SessionId string `json:"session_id"`
	Response  struct {
		TotalCount int    `json:"total_count"`
		UserList   []User `json:"user_list"`
	} `json:"response"`
}

//删除特定路径的字段
func DeletePath() {
	testS := TestStructObj{}
	for i := 0; i < 3; i++ {
		testS.Response.UserList = append(testS.Response.UserList, User{
			Id:           i,
			CreatedAt:    "123",
			UpdatedAt:    "1213",
			DeletedAt:    "123",
			UserName:     "123",
			Organization: "123",
			UserType:     0,
		})
	}

	v, err := jsonvalue.Import(testS)
	if err != nil {
		fmt.Println("err is ", err)
		return
	}
	v.Delete("response", "user_list", 0)
	s, err := v.Marshal()
	if err != nil {
		fmt.Println("err is ", err)
		return
	}
	fmt.Println(string(s))
}

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

type CoefList struct {
	CoefFrame Frame `json:"coef_frame"`
}

type SpeechReqType struct {
	AnimRep struct {
		AlgInfo struct {
			ActionList       []interface{} `json:"action_list"`
			AlglibInfo       string        `json:"alglib_info"`
			AnimCoefList     []CoefList    `json:"anim_coef_list"`
			CoefType         int           `json:"coef_type"`
			ErrMsg           string        `json:"err_msg"`
			ErrNo            int           `json:"err_no"`
			FirstDelay       float64       `json:"first_delay"`
			FrameCount       int           `json:"frame_count"`
			FrameRate        int           `json:"frame_rate"`
			Language         int           `json:"language"`
			OutputCoefFormat int           `json:"output_coef_format"`
			Rtf              float64       `json:"rtf"`
		} `json:"alg_info"`
		ErrMsg    string `json:"err_msg"`
		ErrNo     int    `json:"err_no"`
		SessionId string `json:"session_id"`
	} `json:"anim_rep"`
	Begin bool `json:"begin"`
	End   bool `json:"end"`
}

func (s SpeechReqType) String() string {
	marshal, _ := json.Marshal(s)
	return string(marshal)
}

//指定排序顺序
func SortRuleJson() {
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
	v, _ := jsonvalue.Import(frame)
	keyString := []string{"EH", "UUU", "TTH", "RRR", "AAA"}
	opt := jsonvalue.OptKeySequence(keyString)
	marshal, _ := v.Marshal(opt)
	fmt.Println(string(marshal))
}

func SOrtRUleJson2() {
	frame := SpeechReqType{}
	t := Frame{
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
	coelist := CoefList{
		CoefFrame: t,
	}
	frame.AnimRep.AlgInfo.AnimCoefList = append(frame.AnimRep.AlgInfo.AnimCoefList, coelist)
	v, _ := jsonvalue.Import(frame)
	keyString := []string{"EH", "UUU", "TTH", "RRR", "AAA"}
	opt := jsonvalue.OptKeySequence(keyString)
	marshal, _ := v.Marshal(opt)
	fmt.Println(string(marshal))
	frame2 := SpeechReqType{}
	v.Export(&frame2)
	fmt.Println("export frame2 ", frame2)
}

type TagTest struct {
	Name     int  `json:"name,omitempty"`
	BoolTest bool `json:"btest,omitempty"`
	Fnum     float32
}

func TestFloat() {
	f := 123.123456789
	var v *jsonvalue.V

	v = jsonvalue.NewFloat64(f)
	fmt.Println(v)

	v = jsonvalue.NewFloat64f(f, 'f', 6)
	fmt.Println(v)

	v = jsonvalue.NewFloat64f(f, 'e', 10)
	fmt.Println(v)
	marshalString, _ := v.MarshalString()
	fmt.Println("marsh float ", marshalString)
}

func TestOmitempty() {
	tag := TagTest{}
	tag.Fnum = 1.03874329103
	opt := jsonvalue.OptIgnoreOmitempty()
	v, _ := jsonvalue.Import(tag, opt)
	//v = jsonvalue.NewFloat32f(tag.Fnum, 'f', 2)
	marshal, _ := v.MarshalString()
	fmt.Println("omitempty is ", marshal)
}

type TestJsonStruct struct {
	CostTime      int    `json:"cost_time"`
	ErrMsg        string `json:"err_msg"`
	ErrNo         int    `json:"err_no"`
	SessionId     string `json:"session_id"`
	SpeechRepInfo struct {
		AnimRep struct {
			AlgInfo struct {
				ActionList       []interface{} `json:"action_list"`
				AlglibInfo       string        `json:"alglib_info"`
				CoefType         int           `json:"coef_type"`
				ErrMsg           string        `json:"err_msg"`
				ErrNo            int           `json:"err_no"`
				FirstDelay       float64       `json:"first_delay"`
				FrameCount       int           `json:"frame_count"`
				FrameRate        int           `json:"frame_rate"`
				Language         int           `json:"language"`
				OutputCoefFormat int           `json:"output_coef_format"`
				Rtf              float64       `json:"rtf"`
				T2FAlgId         string        `json:"t2f_alg_id"`
			} `json:"alg_info"`
			ErrMsg    string `json:"err_msg"`
			ErrNo     int    `json:"err_no"`
			SessionId string `json:"session_id"`
		} `json:"anim_rep"`
		Begin     bool `json:"begin"`
		End       bool `json:"end"`
		SpeechRsp struct {
			AlgId      string `json:"alg_id"`
			AlglibInfo string `json:"alglib_info"`
			Autospd    int    `json:"autospd"`
			Codec      string `json:"codec"`
			ErrMsg     string `json:"err_msg"`
			ErrNo      int    `json:"err_no"`
			Final      bool   `json:"final"`
			Fps        int    `json:"fps"`
			Language   int    `json:"language"`
			Manspd     int    `json:"manspd"`
			Procspd    int    `json:"procspd"`
			Sampling   int    `json:"sampling"`
			Sessionid  string `json:"sessionid"`
			ThDim      int    `json:"th_dim"`
		} `json:"speech_rsp"`
	} `json:"speech_rep_info"`
}

func TestDelete() {
	req := TestJsonStruct{}
	v := jsonvalue.New(req)
	//删除不存在的key不会报错
	v.Delete("aabb", "ccdd", 1)
	v.Delete(2)

	marshalString, _ := v.MarshalString()
	fmt.Println("test del ", marshalString)

}

func main() {
	//SortRuleJson()
	//SOrtRUleJson2()
	//TestFloat()
	TestDelete()
}
