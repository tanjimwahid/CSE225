**What it is:** A list built using a plain array (`info[MAX_ITEMS]`) plus a `length` counter to track how many items are actually stored. "Unsorted" = items just sit in insertion order, no sorting logic.

- **Insert** → put new item right after the last one, bump `length`.
- **Delete** → find the item, copy the last item into its spot, shrink `length` (no shifting needed since order doesn't matter).
- **Search** → just loop through checking each slot.

**Same as a linked list?** No.

- This one = **fixed-size array**, all memory reserved upfront (100 slots whether you use them or not).
- Linked list = **nodes connected by pointers**, memory only allocated as you add items, no fixed cap.

Same job (store a list, insert/delete/search), different internal setup — array vs pointer-chained nodes.


**ADT** — Abstract Data Type. Simple version:

An ADT is just a **concept/blueprint** for a data structure — it defines *what operations it supports* (like Insert, Delete, Search) without saying *how* those operations are actually built underneath.

So "**List**" is the ADT — the idea of "a collection of items where you can insert, delete, and retrieve stuff."

How you actually *build* that list can differ:
- Array-based list (what we just did — `UnsortedType` using a plain array)
- Linked list (using pointers/nodes)

Both are "lists" from the outside (same operations: InsertItem, DeleteItem, RetrieveItem, etc.) — that's the ADT part, the interface/contract. But internally they're built totally differently — that's the **implementation**, not the ADT.

Basically: **ADT = the "what it does"**, implementation = **"how it does it."**


Memory:

- The array `info[MAX_ITEMS]` is **not** dynamically allocated (no `new`). It's a fixed member array — it lives wherever the `UnsortedType` object itself lives.
  - `UnsortedType<int> list;` (local var) → whole thing, array included, sits on the **stack**.
  - `UnsortedType<int>* list = new UnsortedType<int>();` → whole thing sits on the **heap**.
- Either way, it's one **contiguous block** of memory — 100 slots reserved right from creation, whether you use 1 or all 100.

Linked list, for comparison: each node is separately `new`'d → always on the **heap**, scattered around, connected via pointers.

Speed:

- Array version is **faster in practice** because the data is contiguous — CPU cache loves that, no pointer-chasing.
- Linked list nodes are scattered in memory, so walking through it means jumping around RAM → more cache misses → slower even when the "steps" count is similar.

Bottom line: array = rigid but fast/cache-friendly. Linked list = flexible but slower due to memory scattering.