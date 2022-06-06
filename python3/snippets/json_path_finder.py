import json


class JsonPathFinder:
    def __init__(self, json_str):
        if isinstance(json_str, dict):
            self.data = json_str
        else:
            self.data = json.loads(json_str,)

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

class JsonDictFilter:
    def __init__(self, json_str):
        if isinstance(json_str, dict):
            self.data = json_str
        else:
            self.data = json.loads(json_str,)

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
            print(f"haha#{val}")
            if isinstance(val,str) and len(val)>3:
                print("haha")
                key_value_iter[key] = ""
        
            if isinstance(val, (dict, list)):
                yield from self.__iter_node(val, cur_path, target)

    def find_all(self, key):
        path_iter = self.__iter_node(self.data, [], key)
        return list(path_iter)

json_str = '''{"ret_code":0,"ret_msg":"succ","session_id":"8df9a729-62b7-435c-a3bf-4b6d7dd0d2bf","response":{"total_count":6,"project_list":[{"id":5,"project_name":"NewProjTest","user_id":1,"user_name":"hulkcao","desc":"this is a new one one"},{"id":7,"project_name":"NewProjTestB","user_id":1,"user_name":"hulkcao","desc":"a new project B"},{"id":8,"project_name":"NewProjTestC","user_id":1,"user_name":"hulkcao","desc":"a new project C"},{"id":9,"project_name":"NewProjTest","user_id":2,"user_name":"testuser","desc":"this test a new des"},{"id":11,"project_name":"NewProjTesthulk","user_id":1,"user_name":"hulkcao","desc":"a new project"},{"id":12,"project_name":"projhulk","user_id":1,"user_name":"hulkcao","desc":"this is a new"}]}}'''

if __name__ == "__main__":
    finder = JsonPathFinder(json_str)
    path_list = finder.find_all("project_name")
    print(path_list)
    for path in path_list:
        target_val = finder.data
        for step in path:
            target_val = target_val[step]
        print(target_val)


    filter = JsonDictFilter(json_str)
    filter.find_all("")
    print(filter.data)