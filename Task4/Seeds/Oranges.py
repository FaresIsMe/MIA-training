def pineapple(number):
     print(number * number)

def multiply_lists(list1, list2):
     result = []
     for i in range(len(list1)):
         result.append(list1[i] * list2[i])
     return result


if __name__ == "__main__":
     pineapple()

