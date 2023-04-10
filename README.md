## UID: 905754103

# A Kernel Seedling

This kernel module creates a file `/proc/count` that contains the number of processes runnning on the system.

## Building

To build this kernel module, run `make` in the root directory (where the Makefile is).

## Running

To load the module, run `sudo insmod proc_count.ko`. This writes to the `/proc/count` file. To view the count, simply run `cat /proc/count`. 

## Cleaning Up

To remove the kernel module / clean up, run `sudo rmmod proc_count`.

## Testing

The kernel release version I tested my module on was `5.14.8-arch1-1`. To get this, I ran `uname -r`.

I ran the provided unit tests, and all 3 of them passed in ~12 seconds.

I also ran a sanity check using `modinfo`, and the output seemed fine.

