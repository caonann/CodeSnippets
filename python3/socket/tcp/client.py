import socket
import time


def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect(('9.134.173.151', 12345))
        print("Connected to the server.")
        client_socket.sendall(b"Hello, server!")
        
        # 暂停，等待用户输入或者一段时间，模拟在数据发送后服务器突然重启的情况
        input("Press Enter after you stop the server to simulate a sudden restart...")

        # 尝试再次发送数据，看看连接状态
        client_socket.sendall(b"Are you still there?")
        print("Data sent after server restart attempt.")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        client_socket.close()
        print("Connection closed.")

if __name__ == "__main__":
    start_client()
