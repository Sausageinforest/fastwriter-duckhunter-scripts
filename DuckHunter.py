import os

def print_menu(actions):
    os.system('cls') # очищаем консоль в Linux/MacOS, для Windows можно использовать 'cls'
    print(actions)
    print("-------------------------------------------------------------")
    print("1. Open WIN+R")
    print("2. Write text or link")
    print("3. Enter")
    print("4. Wait (and number of seconds)")
    print("To exit, press Enter")
    print("-------------------------------------------------------------")

def main():


    name = input("Script name: ")
    f = open(name + ".txt", "a")
    actions = "" # список сделанных действий

    print_menu(actions)

    while True:
        p = input()

        if p == "1":
            f.write("GUI r\n")
            f.write("DELAY 200\n")
            actions += "Opened WIN+R\n"
            print_menu(actions)

        elif p == "2":
            text = input("Text: ")
            f.write(f"STRING {text}\n")
            f.write("DELAY 200\n")
            actions += f"Wrote '{text}'\n"
            print_menu(actions)

        elif p == "3":
            f.write("ENTER\n")
            f.write("DELAY 200\n")
            actions += "Pressed Enter\n"
            print_menu(actions)

        elif p == "4":
            delay = input("Delay time (in milliseconds): ")
            f.write(f"DELAY {delay}\n")
            actions += f"Waited {delay} ms\n"
            print_menu(actions)

        elif p == "exit":
            f.close()
            print("File saved in the program directory!")
            break

if __name__ == "__main__":
    main()
