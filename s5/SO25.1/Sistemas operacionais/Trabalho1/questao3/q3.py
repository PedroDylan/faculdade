import threading
import time
import random
from statistics import mean

class AnimalRoom:
    def __init__(self):
        self.lock = threading.Lock()
        self.state = "Vazia"
        self.dogs_count = 0
        self.cats_count = 0
        self.dogs_waiting = threading.Condition(self.lock)
        self.cats_waiting = threading.Condition(self.lock)
        
        # Métricas
        self.metrics = {
            "dog_wait_times": [],
            "cat_wait_times": [],
            "dog_exec_times": [],
            "cat_exec_times": [],
            "start_time": time.time(),
            "total_animals": 0
        }

    def dogWantsToEnter(self):
        start_wait = time.time()
        with self.lock:
            while self.state == "Gatos":
                print("Cachorro esperando (gatos na sala)...")
                self.dogs_waiting.wait()
            wait_time = time.time() - start_wait
            self.metrics["dog_wait_times"].append(wait_time)
            
            self.dogs_count += 1
            self.state = "Cachorros"
            print(f"Cachorro entrou (Wait: {wait_time:.2f}s)")
            return time.time()  # Retorna o tempo de entrada

    def catWantsToEnter(self):
        start_wait = time.time()
        with self.lock:
            while self.state == "Cachorros":
                print("Gato esperando (cachorros na sala)...")
                self.cats_waiting.wait()
            wait_time = time.time() - start_wait
            self.metrics["cat_wait_times"].append(wait_time)
            
            self.cats_count += 1
            self.state = "Gatos"
            print(f"Gato entrou (Wait: {wait_time:.2f}s)")
            return time.time()  # Retorna o tempo de entrada

    def dogLeaves(self, entry_time):
        with self.lock:
            self.dogs_count -= 1
            exec_time = time.time() - entry_time
            self.metrics["dog_exec_times"].append(exec_time)
            
            if self.dogs_count == 0:
                self.state = "Vazia"
                self.cats_waiting.notify_all()
            print(f"Cachorro saiu (Exec: {exec_time:.2f}s)")

    def catLeaves(self, entry_time):
        with self.lock:
            self.cats_count -= 1
            exec_time = time.time() - entry_time
            self.metrics["cat_exec_times"].append(exec_time)
            
            if self.cats_count == 0:
                self.state = "Vazia"
                self.dogs_waiting.notify_all()
            print(f"Gato saiu (Exec: {exec_time:.2f}s)")

def simulate_dog(room, id):
    time.sleep(random.uniform(0.1, 1.0))
    entry_time = room.dogWantsToEnter()
    time.sleep(random.uniform(0.5, 2.0))
    room.dogLeaves(entry_time)

def simulate_cat(room, id):
    time.sleep(random.uniform(0.1, 1.0))
    entry_time = room.catWantsToEnter()
    time.sleep(random.uniform(0.5, 2.0))
    room.catLeaves(entry_time)

def main():
    room = AnimalRoom()
    threads = []
    room.metrics["total_animals"] = 10  # Total de threads
    
    # Cria threads
    for i in range(10):
        if random.choice([True, False]):
            t = threading.Thread(target=simulate_dog, args=(room, i))
        else:
            t = threading.Thread(target=simulate_cat, args=(room, i))
        threads.append(t)
        t.start()
    
    # Aguarda conclusão
    for t in threads:
        t.join()
    
    # Calcula métricas
    total_time = time.time() - room.metrics["start_time"]
    throughput = room.metrics["total_animals"] / total_time
    
    print("\n--- Métricas ---")
    print(f"Tempo total de simulação: {total_time:.2f}s")
    print(f"Vazão (throughput): {throughput:.2f} animais/segundo")
    
    if room.metrics["dog_wait_times"]:
        print(f"Tempo médio de espera (cachorros): {mean(room.metrics['dog_wait_times']):.2f}s")
    if room.metrics["cat_wait_times"]:
        print(f"Tempo médio de espera (gatos): {mean(room.metrics['cat_wait_times']):.2f}s")
    if room.metrics["dog_exec_times"]:
        print(f"Tempo médio na sala (cachorros): {mean(room.metrics['dog_exec_times']):.2f}s")
    if room.metrics["cat_exec_times"]:
        print(f"Tempo médio na sala (gatos): {mean(room.metrics['cat_exec_times']):.2f}s")

if __name__ == "__main__":
    main()