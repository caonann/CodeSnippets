import json
from typing import List


class JsonPathFinder:
    """json 修改器，给定path可以修改特定路径的值"""

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

    def find_all(self, key) -> List:
        path_iter = self.__iter_node(self.data, [], key)
        return list(path_iter)

    def find_and_get_value(self, key) -> List:
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


json_str = """{"ret_code":0,"ret_msg":"succ","session_id":"8df9a729-62b7-435c-a3bf-4b6d7dd0d2bf","response":{"total_count":6,"project_list":[{"id":5,"project_name":"NewProjTest","user_id":1,"user_name":"hulkcao","desc":"this is a new one one"},{"id":7,"project_name":"NewProjTestB","user_id":1,"user_name":"hulkcao","desc":"a new project B"},{"id":8,"project_name":"NewProjTestC","user_id":1,"user_name":"hulkcao","desc":"a new project C"},{"id":9,"project_name":"NewProjTest","user_id":2,"user_name":"testuser","desc":"this test a new des"},{"id":11,"project_name":"NewProjTesthulk","user_id":1,"user_name":"hulkcao","desc":"a new project"},{"id":12,"project_name":"projhulk","user_id":1,"user_name":"hulkcao","desc":"this is a new"}]}}"""
json_dict = {
    "ret_code": 0,
    "ret_msg": "succ",
    "session_id": "8df9a729-62b7-435c-a3bf-4b6d7dd0d2bf",
    "response": {
        "total_count": 6,
        "project_list": [
            {
                "id": 5,
                "project_name": "NewProjTest",
                "user_id": 1,
                "user_name": "hulkcao",
                "desc": "this is a new one one",
            },
            {
                "id": 7,
                "project_name": "NewProjTestB",
                "user_id": 1,
                "user_name": "hulkcao",
                "desc": "a new project B",
            },
            {
                "id": 8,
                "project_name": "NewProjTestC",
                "user_id": 1,
                "user_name": "hulkcao",
                "desc": "a new project C",
            },
            {
                "id": 9,
                "project_name": "NewProjTest",
                "user_id": 2,
                "user_name": "testuser",
                "desc": "this test a new des",
            },
            {
                "id": 11,
                "project_name": "NewProjTesthulk",
                "user_id": 1,
                "user_name": "hulkcao",
                "desc": "a new project",
            },
            {
                "id": 12,
                "project_name": "projhulk",
                "user_id": 1,
                "user_name": "hulkcao",
                "desc": "this is a new",
            },
        ],
    },
}


if __name__ == "__main__":
    finder = JsonPathFinder(json_dict)
    print(finder.find_and_get_value("project_name"))
    print(finder.find_and_get_value("total_count"))
    print(finder.find_and_get_value("id"))
    finder.find_and_replace("project_name", "xxx")
    print(f"{json_dict=}")
    finder.find_and_replace("notexistkey", "kkk")
    print(f"{json_dict=}")
    