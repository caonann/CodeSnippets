def is_float(a_string: str):
    try:
        float(a_string)
        return True
    except ValueError:
        return False


if __name__ == "__main__":
    test_vals = ["123.9", "1.0", "1", "3", 1.0, 5, "-123.9", -456]
    for item in test_vals:
        assert is_float(item)
    for item in test_vals:
        print(float(item))
