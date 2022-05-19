func isValid(s string) bool {
    stack := make([]rune, 0, len(s))
    for _, c := range s {
        switch c {
        case '(':
            stack = append(stack, ')')
        case '{':
            stack = append(stack, '}')
        case '[':
            stack = append(stack, ']')
        default:
            if len(stack) == 0 || c != stack[len(stack)-1] {
                return false
            }
            stack = stack[:len(stack)-1]
        }
    }
    return len(stack) == 0
}