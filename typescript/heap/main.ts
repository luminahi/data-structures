import { MinHeap } from "./heap.js";

const heap = new MinHeap(7);

heap.insert(1);
heap.insert(4);
heap.insert(8);
heap.insert(5);
heap.insert(7);
heap.insert(9);
heap.insert(2);

console.log(heap.toString());

heap.extractMin();
console.log(heap.toString());

heap.extractMin();
console.log(heap.toString());

heap.extractMin();
console.log(heap.toString());

heap.extractMin();
console.log(heap.toString());
