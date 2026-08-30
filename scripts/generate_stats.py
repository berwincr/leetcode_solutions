import json
import os
from pathlib import Path

# Get repository root
ROOT = Path(__file__).resolve().parent.parent

STATS_FILE = ROOT / "stats.json"
OUTPUT_FILE = ROOT / "assets" / "leetcode-stats.svg"

# Read stats.json
with open(STATS_FILE, "r", encoding="utf-8") as f:
    data = json.load(f)

# LeetHub data
leetcode = data.get("leetcode", {})
shas = leetcode.get("shas", {})

easy = 0
medium = 0
hard = 0

# Count problems from actual entries
for problem_name, problem_data in shas.items():

    if problem_name == "README.md":
        continue

    if not isinstance(problem_data, dict):
        continue

    difficulty = problem_data.get("difficulty", "").lower()

    if difficulty == "easy":
        easy += 1
    elif difficulty == "medium":
        medium += 1
    elif difficulty == "hard":
        hard += 1

total = easy + medium + hard

# Make sure assets directory exists
os.makedirs(OUTPUT_FILE.parent, exist_ok=True)

# Progress bar settings
max_count = max(easy, medium, hard, 1)

def bar_width(value):
    return int((value / max_count) * 350)


# Create SVG
svg = f'''<svg width="800" height="400"
xmlns="http://www.w3.org/2000/svg">

<style>
.title {{
    font: bold 30px Arial;
}}

.total {{
    font: bold 52px Arial;
}}

.label {{
    font: bold 20px Arial;
}}

.number {{
    font: bold 20px Arial;
}}

.small {{
    font: 16px Arial;
}}
</style>

<rect width="100%" height="100%" rx="20" fill="#0d1117"/>

<text x="400" y="55" text-anchor="middle"
class="title" fill="white">
LeetCode Progress
</text>

<text x="400" y="135" text-anchor="middle"
class="total" fill="#58a6ff">
{total}
</text>

<text x="400" y="165" text-anchor="middle"
class="small" fill="#8b949e">
Problems Solved
</text>

<!-- Easy -->
<text x="80" y="225"
class="label" fill="#3fb950">
Easy
</text>

<rect x="200" y="205"
width="350" height="25" rx="12"
fill="#21262d"/>

<rect x="200" y="205"
width="{bar_width(easy)}" height="25" rx="12"
fill="#3fb950"/>

<text x="580" y="225"
class="number" fill="white">
{easy}
</text>

<!-- Medium -->
<text x="80" y="285"
class="label" fill="#d29922">
Medium
</text>

<rect x="200" y="265"
width="350" height="25" rx="12"
fill="#21262d"/>

<rect x="200" y="265"
width="{bar_width(medium)}" height="25" rx="12"
fill="#d29922"/>

<text x="580" y="285"
class="number" fill="white">
{medium}
</text>

<!-- Hard -->
<text x="80" y="345"
class="label" fill="#f85149">
Hard
</text>

<rect x="200" y="325"
width="350" height="25" rx="12"
fill="#21262d"/>

<rect x="200" y="325"
width="{bar_width(hard)}" height="25" rx="12"
fill="#f85149"/>

<text x="580" y="345"
class="number" fill="white">
{hard}
</text>

</svg>
'''

# Save SVG
with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
    f.write(svg)

print("LeetCode stats generated successfully!")
print(f"Easy: {easy}")
print(f"Medium: {medium}")
print(f"Hard: {hard}")
print(f"Total: {total}")
