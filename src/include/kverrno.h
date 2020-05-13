#ifndef __KVERRNO_H
#define __KVERRNO_H

enum kverrno{
    KV_ESUCCESS = 0,
    KV_ESHARD_NOT_EXIST,
    KV_EITEM_NOT_EXIST,
    KV_ESHARD_OUT_OF_RANGE,
    KV_EIO,
    KV_EMEM,
    KV_ECACHE,
    KV_EFULL,
    KV_EINVAL,
    KV_EMPTY,
    KV_EOP_UNKNOWN,
    KV_EOP_RACE
};

#endif