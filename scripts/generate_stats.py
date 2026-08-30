import json
import os
import re
from pathlib import Path

# Repository root
ROOT = Path(__file__).resolve().parent.parent

STATS_FILE = ROOT / "stats.json"
OUTPUT_FILE = ROOT / "assets" / "leetcode-stats.svg"


# -----------------------------
# READ stats.json
# -----------------------------
with open(STATS_FILE, "r", encoding="utf-8") as f:
    data = json.load(f)

leetcode = data.get("leetcode", {})
shas = leetcode.get("shas", {})


# -----------------------------
# INITIALIZE COUNTERS
# -----------------------------
easy = 0
medium = 0
hard = 0


# -----------------------------
# FIND DIFFICULTY FROM README
# -----------------------------
def get_difficulty_from_readme(problem_name):
    readme_file = ROOT / problem_name / "README.md"

    if not readme_file.exists():
        return ""

    try:
        with open(readme_file, "r", encoding="utf-8") as f:
            content = f.read().lower()

        # Look for difficulty labels
        if re.search(r"\bmedium\b", content):
            return "medium"

        if re.search(r"\beasy\b", content):
            return "easy"

        if re.search(r"\bhard\b", content):
            return "hard"

    except Exception as e:
        print(f"Could not read {readme_file}: {e}")

    return ""


# -----------------------------
# COUNT ACTUAL PROBLEMS
# -----------------------------
for problem_name, problem_data in shas.items():

    # Skip root README entry
    if problem_name == "README.md":
        continue

    if not isinstance(problem_data, dict):
        continue

    # First try getting difficulty from stats.json
    difficulty = problem_data.get("difficulty", "").lower()

    # If missing, try reading the problem README
    if difficulty not in ("easy", "medium", "hard"):
        difficulty = get_difficulty_from_readme(problem_name)

    print(f"{problem_name} -> {difficulty}")

    # Count problems
    if difficulty == "easy":
        easy += 1

    elif difficulty == "medium":
        medium += 1

    elif difficulty == "hard":
        hard += 1


# -----------------------------
# TOTAL
# -----------------------------
total = easy + medium + hard

print("\n------ LEETCODE STATS ------")
print(f"Easy: {easy}")
print(f"Medium: {medium}")
print(f"Hard: {hard}")
print(f"Total: {total}")
print("----------------------------\n")


# -----------------------------
# CREATE ASSETS DIRECTORY
# -----------------------------
os.makedirs(OUTPUT_FILE.parent, exist_ok=True)


# -----------------------------
# CALCULATE BAR WIDTH
# -----------------------------
max_count = max(easy, medium, hard, 1)


def bar_width(value):
    return int((value / max_count) * 350)


# -----------------------------
# GENERATE SVG
# -----------------------------
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

<!-- Background -->
<rect width="100%" height="100%" rx="20" fill="#0d1117"/>

<!-- Title -->
<text x="400" y="55" text-anchor="middle"
class="title" fill="white">
LeetCode Progress
</text>

<!-- Total -->
<text x="400" y="135" text-anchor="middle"
class="total" fill="#58a6ff">
{total}
</text>

<text x="400" y="165" text-anchor="middle"
class="small" fill="#8b949e">
Problems Solved
</text>


<!-- EASY -->

<text x="80" y="225"
class="label" fill="#3fb950">
Easy
</text>

<rect x="200" y="205"
width="350" height="25"
rx="12"
fill="#21262d"/>

<rect x="200" y="205"
width="{bar_width(easy)}"
height="25"
rx="12"
fill="#3fb950"/>

<text x="580" y="225"
class="number"
fill="white">
{easy}
</text>


<!-- MEDIUM -->

<text x="80" y="285"
class="label" fill="#d29922">
Medium
</text>

<rect x="200" y="265"
width="350" height="25"
rx="12"
fill="#21262d"/>

<rect x="200" y="265"
width="{bar_width(medium)}"
height="25"
rx="12"
fill="#d29922"/>

<text x="580" y="285"
class="number"
fill="white">
{medium}
</text>


<!-- HARD -->

<text x="80" y="345"
class="label" fill="#f85149">
Hard
</text>

<rect x="200" y="325"
width="350" height="25"
rx="12"
fill="#21262d"/>

<rect x="200" y="325"
width="{bar_width(hard)}"
height="25"
rx="12"
fill="#f85149"/>

<text x="580" y="345"
class="number"
fill="white">
{hard}
</text>


</svg>
'''


# -----------------------------
# SAVE SVG
# -----------------------------
with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
    f.write(svg)


print("LeetCode stats visualization generated successfully!")
print(f"Output: {OUTPUT_FILE}")
