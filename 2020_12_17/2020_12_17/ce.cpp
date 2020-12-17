int LRU(int total_pf) {      /*最近最久未使用算法（使用时钟计数器）*/
	int min, minj, present_time;
	initialize(total_pf);
	present_time = 0;
	for (int i = 0; i<total_instruction; i++){
		if (pl[page[i]].pfn == INVALID) {            //页面失效，不在内存中
			diseffect++;
			if (freepf_head == NULL) {             //内存无空闲页面
				min = 32767;
				for (int j = 0; j < total_vp; j++) {  //找出内存块中time的最小值
					if (min > pl[j].time && pl[j].pfn != INVALID)  // 查询页表
					{
						min = pl[j].time;
						minj = j;  // 记下内存块号
					}
				}
				freepf_head = &pfc[pl[minj].pfn];   //腾出一个单元（对应的内存块）
				pl[minj].pfn = INVALID;
				pl[minj].time = -1;
				freepf_head->next = NULL;
			}
			pl[page[i]].pfn = freepf_head->pfn;   //有空闲页面,改为有效（内存块号）
			pl[page[i]].time = present_time;
			freepf_head = freepf_head->next;      //减少一个free 页面
		}
		else {
			pl[page[i]].time = present_time;        //命中则设置时间
		}
		present_time++;
	}
	printf("LRU:%6.4f\n", 1 - diseffect / 320.0);
	return 0;
}