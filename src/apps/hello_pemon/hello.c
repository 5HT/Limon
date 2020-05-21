#include <stdint.h>
#include <stdbool.h>
#include "kvs.h"

#include "spdk/env.h"
#include "spdk/event.h"

struct _hello_context{
    int i;
};

static void
hello_start(void*ctx, int kverrno){
    printf("Hello pemon~\n");
}

static void
_kvs_opts_init(struct kvs_start_opts *opts){
    opts->devname = "Nvme0n1";
    opts->kvs_name = "hello_pemon";
    opts->max_cache_chunks = 1024;
    opts->max_io_pending_queue_size_per_worker = 64;
    opts->max_request_queue_size_per_worker = 128;
    opts->nb_works = 1;
    opts->reclaim_batch_size = 16;
    opts->reclaim_percentage_threshold = 80;
    opts->startup_fn = hello_start;
    opts->startup_ctx = NULL;
}

int
main(int argc, char **argv){
    struct spdk_app_opts opts = {0};
	int rc = 0;

	spdk_app_opts_init(&opts);

	opts.name = "hello_pemon";
	if ((rc = spdk_app_parse_args(argc, argv, &opts, NULL, NULL,
				      NULL, NULL)) !=
	    SPDK_APP_PARSE_ARGS_SUCCESS) {
		exit(rc);
	}

    struct kvs_start_opts kvs_opts;
    _kvs_opts_init(&kvs_opts);

    kvs_opts.spdk_opts = &opts;

    kvs_start_loop(&kvs_opts);

    //Shall not be here.
    printf("Kvs start failed\n");
    
	return -1;
}