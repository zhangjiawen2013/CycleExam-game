--------------------------------------------------
Test Version Numbering
The beta releases use a "YYwWWx" scheme: year (two digits) + week number + suffix. For example, "26w10a" is the first beta of week 10 in 2026.
Weeks start from Jan 1 and count every 7 days. The suffix is a lowercase letter distinguishing multiple builds in the same week.
--------------------------------------------------
Release Version Numbering
Official releases use "Year.Major.Minor" (minor optional). e.g. "26.1.1" denotes 2026, major version 1, minor version 1.
An official version is published after sufficient testing and no critical issues remain.
Once released, it supersedes any beta versions from the same week.
--------------------------------------------------
Version 26w10a (2026/03/08):
  1. Added main menu and partial functionality
  2. Fixed screen flicker when entering non-numeric characters

Version 26w11a pre + 26w11a (2026/03/15):
  1. Drafted game story outline
  2. Implemented "Bed End 1" ending and preceding scenes
  3. Refactored changelog display function
  4. Refactored story selection logic
  5. Added runtime logging feature
  6. Replaced all cout with cfout to output to console and log file simultaneously
--------------------------------------------------