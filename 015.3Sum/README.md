_accept.cpp表示被接受的程序，另一个则因为超时没有通过。
不能通过是因为超时了，是因为虽然对输入数组进行了排序，但是没有对待选中组合中的第一个元素>0和等于0的情况做特殊处理，及时break，导致超时。