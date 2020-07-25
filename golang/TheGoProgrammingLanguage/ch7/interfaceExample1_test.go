package main

import (
	"testing"
)

func TestByteCount_Write(t *testing.T) {
	type args struct {
		p []byte
	}
	tests := []struct {
		name    string
		b       *ByteCount
		args    args
		wantN   int
		wantErr bool
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			gotN, err := tt.b.Write(tt.args.p)
			if (err != nil) != tt.wantErr {
				t.Errorf("ByteCount.Write() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if gotN != tt.wantN {
				t.Errorf("ByteCount.Write() = %v, want %v", gotN, tt.wantN)
			}
		})
	}
}

func Test_main(t *testing.T) {
	tests := []struct {
		name string
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			main()
		})
	}
}
