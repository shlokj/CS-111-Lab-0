#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry* proc_count_entry;

static int seq_show(struct seq_file *s, void *v) {
	int process_count = 0;
	struct task_struct* t;
	for_each_process(t) {
		process_count++;
	}
	seq_printf(s, "%d\n", process_count);
	return 0;
}

static int __init proc_count_init(void)
{
	pr_info("proc_count: init\n");
	proc_count_entry = proc_create_single("count", 0644, NULL, seq_show);
	return 0;
}


static void __exit proc_count_exit(void)
{
	proc_remove(proc_count_entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Shlok Jhawar");
MODULE_DESCRIPTION("This kernel module creates a file /proc/count that contains the number of processes runnning on the system.");
MODULE_LICENSE("GPL");
