parts = []
while True:
        part = input()
        if part:
            parts.append(part)
        else:
            break


def largest_number(parts):
    if not parts:
        return '0'
    
    for i in range(len(parts) - 1):
        for j in range(len(parts) - i - 1):
            if parts[j] + parts[j + 1] < parts[j + 1] + parts[j]:
                parts[j], parts[j + 1] = parts[j + 1], parts[j]
    return ''.join(parts)


print(largest_number(parts))