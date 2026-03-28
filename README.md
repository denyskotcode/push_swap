# 🔄 Push_swap - Data Sorting Project

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language C">
  <img src="https://img.shields.io/badge/School-42-black.svg" alt="School 42">
  <img src="https://img.shields.io/badge/Algorithm-Cost--Based%20%28Greedy%29-success.svg" alt="Algorithm">
</p>

> *"Sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions."*

## 🌟 About the Project

**Push_swap** is an algorithmic project at **School 42**. The objective is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

The project involves two stacks: **Stack A** (contains a random amount of negative and/or positive numbers which cannot be duplicated) and **Stack B** (is empty). The goal is to sort the numbers in Stack A in ascending order.

## 🧠 My Algorithm

To achieve maximum efficiency and minimal operation count, I implemented a **Cost-Based (Greedy) Algorithm**. 

Here is how it works under the hood:
1. **Pre-sorting (A to B):** Elements are pushed from Stack A to Stack B based on average values (`get_avg`), leaving only a few elements in A. This ensures a rough preliminary division.
2. **Cost Calculation:** For every element in Stack B, the algorithm calculates the exact "cost" (number of operations) required to move it to its correct sorted position in Stack A. The `t_move_cost` structure evaluates all possible rotation combinations (`ra`+`rb`, `rra`+`rrb`, `ra`+`rrb`, `rra`+`rb`).
3. **Execution:** The element with the absolute lowest calculated total cost (`get_cheapest`) is chosen and pushed to Stack A using the most efficient combined operations (like `rr` or `rrr`).
4. **Final Alignment:** Once Stack B is empty, Stack A is rotated until the absolute minimum value is at the top.

## 🛠️ Instructions Set

The sorting is strictly limited to these operations:
* `sa` / `sb` / `ss` : Swap the first 2 elements at the top of stack a / b / both.
* `pa` / `pb` : Push the top element from one stack to another.
* `ra` / `rb` / `rr` : Shift up all elements of stack a / b / both by 1.
* `rra` / `rrb` / `rrr` : Shift down all elements of stack a / b / both by 1.

## 🚀 Build and Usage

**1. Clone the repository:**
```bash
git clone [https://github.com/YOUR_USERNAME/push_swap.git](https://github.com/YOUR_USERNAME/push_swap.git)
cd push_swap


---

## License

MIT © [denyskotcode](https://github.com/denyskotcode) — see [LICENSE](LICENSE) for details.