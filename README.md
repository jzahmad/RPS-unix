## Rock, Paper, Scissors Game (Unix)

This repository contains a simple Rock, Paper, Scissors game implemented using C and Unix sockets for communication
between a server and a client.

### Summary

This project demonstrates a basic networked game where a client can play against a server. The server randomly chooses
one of the three options (Rock, Paper, Scissors), and the client has to enter their choice. The game then determines the
winner based on the classic rules of Rock, Paper, Scissors.

### Features

* **Server-Client Architecture:** The game utilizes a server-client architecture to allow two separate processes (one
server and one client) to interact.
* **Unix Sockets:** The communication between the server and client is established using Unix sockets.
* **User Input:** The client is prompted to enter their choice via the command line.
* **Random Server Choice:** The server generates a random choice for each round.
* **Result Display:** The client receives the server's choice and the result (win, lose, or tie) of the round.
* **Multiple Rounds:** The game allows players to play multiple rounds until they choose to exit.
* **Input Validation:** The client input is validated to ensure it is one of the three valid options.

### Tech Stack

* **Language:** C
* **Framework:** Unix Sockets

### Installation and Dependencies

No external dependencies are required for this project. You will only need a Unix-based system with a C compiler.

### Running the Project Locally

1. **Clone the Repository:**
```bash
git clone https://github.com/jzahmad/RPS-unix.git
```

2. **Compile the Code:**
```bash
cd RPS-unix
gcc server.c -o server
gcc client.c -o client
```

3. **Run the Server:**
```bash
./server
```

4. **Run the Client:**
```bash
./client
```

You can open the `server` and `client` in separate terminal tabs. The server will be listening for a connection from the
client.

5. **Playing the Game:**
* The client will prompt you to enter your choice (ROCK, PAPER, or SCISSOR).
* Enter your choice in all capital letters.
* The client will display the server's choice and the result of the round.
* You can play multiple rounds by entering 'y' when prompted.
* Enter 'n' to exit the game.

### Configuration

* **Port Number:** The `PORTNUM` macro in both `server.c` and `client.c` defines the port the server will listen on. You
can change this to a different port if desired.

### Testing

* Run the server and client in separate terminal tabs.
* Enter different choices on the client side and verify the server's choice and the result.
* Test the input validation by entering an invalid choice (e.g., "rock", "p", or "scissors").
* Try playing multiple rounds and then exiting the game.

### Contributing

Contributions to this project are welcome! Feel free to fork the repository and submit pull requests for bug fixes,
improvements, or new features. Please follow the existing code style and write clear, concise commit messages.

### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

### ScreenShots

![image server(L) , client(R)](https://github.com/jzahmad/RPS-unix/assets/140528310/47483f3f-ac31-41a7-8932-61cc550aa025)


