import socket
from _thread import *

server = "26.224.79.246"
port = 32135

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.bind((server, port))
except socket.error as e:
    str(e)

s.listen(2)
print("Esperando uma conexão, Server iniciado.")

def read_pos(str): # string to tuple
    str = str.split(",")
    return int(str[0]), int(str[1]), int(str[2])

def make_pos(tup): # tuple to string
    return str(tup[0]) + "," + str(tup[1]) + "," + str(tup[2])


pos= [(450,630,0),(800,630,0)]  # Posição inicial


def threaded_client(conn, player):
    players = False
    while not players:
        if currentPlayer > 1:
            players = True
    conn.send(str.encode(make_pos(pos[player])))
    reply = ""
    while True:
        try:
            data = read_pos(conn.recv(2048).decode())
            pos[player] = data

            if not data:
                print("Desconectado.")
                break
            else:
                if player == 1:
                    reply = pos[0]
                else:
                    reply = pos[1]

                print("Recebido: ", data)
                print("Enviando: ", reply)

                conn.sendall(str.encode(make_pos(reply)))
        except:
            break

    print("Conexão perdida.")
    conn.close()

currentPlayer = 0
while True:
    conn, addr = s.accept()
    print("Conectado à: ", addr)

    start_new_thread(threaded_client, (conn, currentPlayer))

    currentPlayer += 1