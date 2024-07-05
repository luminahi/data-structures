import { Queue } from "./queue.js";

const queue = new Queue<number>();

queue.enqueue(10);
queue.enqueue(50);
queue.enqueue(90);
queue.enqueue(1000);

queue.dequeue();
queue.dequeue();
queue.dequeue();
queue.dequeue();

queue.enqueue(0);
queue.enqueue(50);
queue.enqueue(-1);
queue.enqueue(100);

queue.print();

console.log(queue.toString());
