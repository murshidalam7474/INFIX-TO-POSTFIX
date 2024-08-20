class InfixToPostfixConverter:
    def __init__(self, infix):
        self.infix = infix
        self.stack = []
        self.postfix = [] 

    def precedence(self, x):
        if x == '+' or x == '-':
            return 1
        elif x == '*' or x == '/':
            return 2
        return 0

    def is_operand(self, x):
        return x not in ['+', '-', '*', '/', '(', ')']

    def convert(self):
        self.stack.append('#')
        
        for ch in self.infix:
            if self.is_operand(ch):
                self.postfix.append(ch)
            elif ch == '(':
                self.stack.append(ch)
            elif ch == ')':
                while self.stack and self.stack[-1] != '(':
                    self.postfix.append(self.stack.pop())
                self.stack.pop()  # Remove '(' from the stack
            else:
                while (self.stack and self.stack[-1] != '(' and 
                       self.precedence(ch) <= self.precedence(self.stack[-1])):
                    self.postfix.append(self.stack.pop())
                self.stack.append(ch)

        while self.stack and self.stack[-1] != '#':
            self.postfix.append(self.stack.pop())

        return ''.join(self.postfix)

if __name__ == "__main__":
    infix = "a+b/c*(d+e*f)-g"
    converter = InfixToPostfixConverter(infix)
    postfix = converter.convert()
    print(postfix)
