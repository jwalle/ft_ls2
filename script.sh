while true
do
	echo "==================================="
	./ft_ls | grep -v grep | grep -v vim
	echo "==================================="
	leaks ft_ls | grep leaked
	echo "==================================="
	sleep 5
	clear
done