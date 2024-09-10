import json


def sum_numbers(json_data):
    if isinstance(json_data, int):
        return json_data
    elif isinstance(json_data, list):
        return sum(sum_numbers(item) for item in json_data)
    elif isinstance(json_data, dict):
        if "red" in json_data.values():
            return 0
        else:
            return sum(sum_numbers(item) for item in json_data.values())
    return 0


with open('data.txt', 'r') as file:
    json_string = file.read()

json_data = json.loads(json_string)

result = sum_numbers(json_data)
print(result)
