## key -> multi-values (list)
```python
from collections import defaultdict
d = defaultdict(list)
d['a'].append(1)
d['a'].append(2)
d['b'].append(4)

for k, v in d.items():
   	print(k)
	print(v)
```

## key -> multi-values (set)
```python
from collections import defaultdict
d = defaultdict(set)
d['a'].add(1)
d['a'].add(2)
d['b'].add(4)

for k, v in d.items():
   	print(k)
	print(v)
```