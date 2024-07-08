import { LinkedList } from "./linked-list.js";

const numberList = new LinkedList<number>();
const nameList = new LinkedList<string>();

numberList.insert(20);
numberList.insert(40);
numberList.insert(60);
numberList.insert(80);

numberList.print();

numberList.remove();
numberList.remove();
numberList.remove();

numberList.print();
console.log(numberList.toString());
