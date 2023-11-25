# Lakeshore Language Spec

## Syntax

### Comments

```lua
-- Single-line comment
--[[ Multi-line comment
Same as lua
]]
```

### Functions

```lua
def factorial(n: int): int
    let res: int = 1
    for i in [2..n] do 
        res *= i
    end
   res -- Expression-based, so this is implicitly returned
end
}
```

### Control Flow

```lua
if (cond) then
    -- body
elseif 
    -- body
else
    -- body
end
}
```

### Looping

```lua
-- While loops
while cond do
    -- something
end

-- Basic compact for loop
for obj in objects do
    println(obj)```
end

-- Range-based for
for i in [10..0] do
    println("Launch in {i}")
end
```

### Tables

```lua
let foo: tbl = [] -- Create an empty table
let bar: tbl = [x = 5] -- Create a table with a key-val pair

```
