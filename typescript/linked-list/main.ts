type NodeObject<T> = {
    value: T;
    next: NodeObject<T> | null;
};

class LinkedList<T> {
    private head: NodeObject<T> | null;

    public constructor() {
        this.head = null;
    }

    private createNode(value: T): NodeObject<T> {
        return { value, next: null };
    }

    public insert(value: T): void {
        const node = this.createNode(value);
        node.next = this.head;
        this.head = node;
    }

    public remove(): void {
        if (!this.head) return;
        this.head = this.head.next;
    }

    public print(): void {
        let iterator = this.head;
        while (iterator) {
            process.stdout.write(`[${iterator.value}]-> `);
            iterator = iterator.next;
        }
        process.stdout.write("\n");
    }

    public toString() {
        return `HEAD [${this.head?.value}]`;
    }
}

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
