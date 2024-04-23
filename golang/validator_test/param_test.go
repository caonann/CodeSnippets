package main

import (
	"testing"

	"github.com/go-playground/validator"
)

type RequiredFields struct {
	SessionID        string `json:"session_id,omitempty" validate:"required"`
	RequestID        string `json:"request_id,omitempty" validate:"required"`
	AppID            int    `json:"app_id,omitempty" validate:"required,gte=10000"`
	Version          string `json:"version,omitempty" validate:"required"`
	RoundID          string `json:"round_id,omitempty"`
	Stream           bool   `json:"stream,omitempty"`
	CalllerID        string `json:"caller_id,omitempty"`
	CalllerName      string `json:"caller_name,omitempty"`
	PreferRoundCount int    `json:"ctx_windows_size"`
}

func TestValidator(t *testing.T) {
	r1 := RequiredFields{}
	r1.AppID = 999
	err := validator.New().Struct(r1)
	if err != nil {
		t.Errorf("Error: %v", err)
	}
}
