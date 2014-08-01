
echo "Comp employees:"
grep "Comp" file1 | awk '{print $1}'
echo "Mech employees:"
grep "Mech" file1 | awk '{print $1}'
echo "Electronics employees:"
grep "Electronics" file1 | awk '{print $1}'