import { Stack } from "./stack.js";

const stack = new Stack<number>();

stack.push(30);
stack.push(60);
stack.push(90);

stack.print();

stack.pop();
stack.pop();

stack.print();

stack.push(1000);
stack.push(1001);

stack.print();

console.log(stack.toString());
