class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if len(token) > 1 or token.isdigit():
                stack.append(int(token))
            else:
                if token == '+':
                    stack[-2] += stack[-1]
                elif token == '-':
                    stack[-2] -= stack[-1]
                elif token == '*':
                    stack[-2] *= stack[-1]
                elif token == '/':
                    stack[-2] = int(float(stack[-2]) / stack[-1])
                stack.pop()
        return stack[0]
