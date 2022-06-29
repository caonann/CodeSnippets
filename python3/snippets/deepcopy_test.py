import json
import sys
from copy import deepcopy


class JsonPathFinder:
    """json 修改器,给定path可以修改特定路径的值"""

    def __init__(self, data):
        if isinstance(data, dict):
            self.data = data
        else:
            self.data = json.loads(
                data,
            )

    def __iter_node(self, rows, road_step, target):
        if isinstance(rows, dict):
            key_value_iter = (x for x in rows.items())
        elif isinstance(rows, list):
            key_value_iter = (x for x in enumerate(rows))
        else:
            return
        for key, val in key_value_iter:
            cur_path = road_step.copy()
            cur_path.append(key)
            if key == target:
                yield cur_path
            if isinstance(val, (dict, list)):
                yield from self.__iter_node(val, cur_path, target)

    def find_all(self, key):
        path_iter = self.__iter_node(self.data, [], key)
        return list(path_iter)

    def find_and_get_value(self, key):
        path_list = self.find_all(key)
        return self.__traverse_path(path_list)

    def find_and_replace(self, key, target_val) -> None:
        path_list = self.find_all(key)
        self.__traverse_path(path_list, target_val)

    def __traverse_path(self, path_list, replace_val=None):
        target_val_list = []
        for path in path_list:
            target_val = self.data
            for idx, step in enumerate(path, start=1):
                if idx == len(path) and replace_val:
                    target_val[step] = replace_val
                target_val = target_val[step]
            target_val_list.append(target_val)
        return target_val_list


def filter_data(data):
    try:
        _ = deepcopy(data)
        finder = JsonPathFinder(_)
        finder.find_and_replace("audio", "x")
        res_str = json.dumps(finder.data, default=str)
    except:
        raise
    return res_str


if __name__ == "__main__":
    with open("/tmp/file", "r") as f:
        file_content = f.read()
        file_size = sys.getsizeof(file_content)
        print(f"file byte size {file_size}")
    data_dict = {
        "ret_code": 0,
        "ret_msg": "succ",
        "session_id": ("83f23fb9-b576-403f-bf76-609df533b704"),
        "response": {
            "result": {
                "sentence": {
                    "words": [
                        {"word": "", "start": 0, "end": 110},
                        {"word": "快", "start": 110, "end": 240},
                        {"word": "手", "start": 240, "end": 520},
                        {"word": "vip", "start": 520, "end": 900},
                        {"word": "六", "start": 900, "end": 1120},
                        {"word": "六", "start": 1120, "end": 1320},
                        {"word": "六", "start": 1320, "end": 1680},
                        {"word": "", "start": 1680, "end": 1890},
                        {"word": "京", "start": 1890, "end": 2070},
                        {"word": "东", "start": 2070, "end": 2220},
                        {"word": "六", "start": 2220, "end": 2410},
                        {"word": "一", "start": 2410, "end": 2500},
                        {"word": "八", "start": 2500, "end": 2680},
                        {"word": "快", "start": 2680, "end": 2890},
                        {"word": "来", "start": 2890, "end": 3040},
                        {"word": "买", "start": 3040, "end": 3390},
                        {"word": "", "start": 3390, "end": 3500},
                    ],
                    "text": "快手vip六百六十六，京东六百一十八快来买！",
                    "startPadding": 0,
                },
                "sampling": 24000,
                "codec": "pcm",
                "audio": bytes(file_content, encoding="utf-8"),
            }
        },
    }
    _ = filter_data(data_dict)
    _ = json.loads(_)
    print(f"ret is {len(_['response']['result']['audio'])}")
    print(f"origin data: {len(data_dict['response']['result']['audio'])}")
    print(f"type of object {type(data_dict['response']['result']['audio'])}")
