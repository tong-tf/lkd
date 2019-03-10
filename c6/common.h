#ifndef COMMON_H
#define COMMON_H

#define TAG "TEST"
#define LOG(fmt,args...) printk(TAG "[%s:%d]" fmt, __func__, __LINE__, ##args)


#endif