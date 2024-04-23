package main

import (
	"encoding/json"
	"fmt"
)

type AgentsParam struct {
	NpcID string `json:"npc_id,omitempty"`
}

func main() {
	curdata := map[string]any{
		"a": AgentsParam{NpcID: "abc"},
	}

	curdata2 := map[string]any{
		"b": []map[string]any{curdata},
	}
	jsonData, err := json.Marshal(curdata2)
	if err != nil {
		fmt.Println("Error marshalling JSON:", err)
		return
	}

	fmt.Println(string(jsonData))
}
