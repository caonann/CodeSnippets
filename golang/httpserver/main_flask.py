import time

from flask import Flask, jsonify, request

app = Flask(__name__)


@app.route("/benchmark", methods=["GET"])
def benchmark():
    start = time.perf_counter()
    if request.args.get("enable_sleep", 0, int):
        time.sleep(1)
    end = time.perf_counter()
    print("{} took {} ms".format("benchmark", (end - start) * 1000))
    return jsonify({"message": "Benchmark path hit done!"})


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
