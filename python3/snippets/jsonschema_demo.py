import jsonschema

schema = {
    "type": "object",
    "properties": {
        "price": {"type": "number"},
        "name": {"type": "string"},
    },
}

try:
    jsonschema.validate(
        instance={"name": "Eggs", "price": "34.99", "aa": "c"}, schema=schema
    )
except jsonschema.ValidationError as e:
    print(e)
