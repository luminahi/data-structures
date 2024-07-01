type StackNode<T> = {
    value: T;
    next: StackNode<T> | null;
};

export class Stack<T> {
    private head: StackNode<T> | null;
    private size: number;

    public constructor() {
        this.head = null;
        this.size = 0;
    }

    private createNode(value: T): StackNode<T> {
        return { value, next: null };
    }

    public push(value: T) {
        let node = this.createNode(value);
        node.next = this.head;
        this.head = node;
        this.size++;
    }

    public pop(): T | void {
        if (!this.head) return;
        const node = this.head;
        this.head = this.head.next;
        this.size--;
        return node.value;
    }

    public print(): void {
        let iterator = this.head;
        process.stdout.write("[TOP] ");
        while (iterator) {
            process.stdout.write(`[${iterator.value}]-> `);
            iterator = iterator.next;
        }
        process.stdout.write("[BOTTOM]\n");
    }

    public getSize(): number {
        return this.size;
    }

    public toString(): string {
        return `[TOP: ${this.head?.value}] ::: Size: ${this.size}`;
    }
}
