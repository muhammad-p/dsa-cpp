# Data Structures and Algorithms
This is my central repository for learning Data Structures and Algorithms, which I built as part of my journey to crack top product based company interviews and competitive programming. This is a complete living timeline of my problem solving growth and structural optimization.

## My Core Development Philosophy: Pure Logic, Smart Automation
> [!IMPORTANT]
> To ensure absolute integrity and true mastery of these concepts, every file in this repository strictly adheres to a disciplined dual-development model:
>* **Core Logic (100% Hand-Written):** Every data structure implementation, algorithmic mechanism, pointer manipulation, and edge-case guard rail is written entirely by myself from scratch. I do not use code assistants, Copilot, or generative AI to write the actual solutions. 
>* **The Main Function & Test Harness (AI-Generated):** Manual building of comprehensive, automated test suites and mock data insertion pipelines by hand can be tedious, time-consuming process. The `main()` function in these files is AI generated to be a robust test harness, to maximize efficiency. This automates the validation process and prints separate `PASSED` or `FAILED` dashboards for various edge cases, so I can focus entirely on implementing the actual data structure logic.

---
## Testing & Verification Blueprint

Every algorithm implemented here is subjected to a rigorous automated verification pass. Instead of utilizing slow, manual interactive command-line inputs (`std::cin`), the driver code in `main()` automatically executes a diverse matrix of test states:

1. Normal and Optimal Paths: Examination of normal, valid data, average case inputs, and expected linear/structural paths of execution.
2. Boundary & Extremal Conditions: Operational checks for minimal, maximal and empty input structures (e.g. zero-values, single-element collections, null references or structural termination points).
3. Structural & Layout Hazards: test stress logic on complex data arrangements such as structural cycles, recursive depth limits, overlapping windows, and heavily skewed data distributions.
4. Parameter Safety & Constraints: Validation of out-of-bounds inputs, negative ranges, invalid indexing, integer overflow boundaries, violation of algorithmic preconditions.

The code executes in a fraction of a millisecond by eliminating interactive inputs and instead using hardcoded, automated test matrices. This prepares the whole codebase for benchmarking and makes it easy to debug.

This approach ensures that the self-written logic is production-grade, memory-safe and survivable in extreme edge cases.

---
## Repository Blueprint

The codebase is meticulously decoupled to separate abstract data storage mechanisms from procedural problem-solving engines:

* **`📁 Implementations of Data Structures`**: Custom, ready to use templates of fundamental primitives built from the ground up.
* **`📁 Algorithms`**: Isolated, highly optimized procedural solutions tackling classic competitive and interview problems.

---
## How to Run

Each file is self-contained with an automated test harness in `main()`.

```bash
# Compile
g++ -std=c++20 -Wall "Algorithms/Linked List/kGroupReversal.cpp" -o output

# Run
./output
```

Expected output prints `PASSED` or `FAILED` for each test case automatically.

---
*“An elegant algorithm is the result of rigorous manual tracing; an exhaustive test suite is the result of smart automation.”*

---
