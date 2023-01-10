# -*- coding: utf-8 -*-
import json
from typing import Any

import json_path_finder as finder


class MyEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, LogFilter):
            return "kkkk"
        if isinstance(obj, bytes):
            return str(obj)
        return json.JSONEncoder.default(self, obj)


class LogFilter:
    black_list=["audio","tts_audio"]
    def __call__(self, *args: Any, **kwds: Any) -> Any:
        print(args, kwds)
        data = args[0]
        f = finder.JsonPathFinder(data)
        f.find_and_replace("audio", "xxxx")
        return json.dumps(data, cls=MyEncoder)


if __name__ == "__main__":
    demo_dict = {"a": "aaa", "b": 123, "audio": "AAAAA"}
    dump_str = json.dumps(LogFilter(), cls=MyEncoder)
    print(dump_str)
    print(MyEncoder().encode(demo_dict))
    demo_dict.update({"c": LogFilter()})
    print(MyEncoder().encode(demo_dict))
    demo_dict.update({"d": b"aaaaa"})
    print(MyEncoder().encode(demo_dict))
    filter = LogFilter()
    print(filter(demo_dict))
