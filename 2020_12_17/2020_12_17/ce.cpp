int LRU(int total_pf) {      /*������δʹ���㷨��ʹ��ʱ�Ӽ�������*/
	int min, minj, present_time;
	initialize(total_pf);
	present_time = 0;
	for (int i = 0; i<total_instruction; i++){
		if (pl[page[i]].pfn == INVALID) {            //ҳ��ʧЧ�������ڴ���
			diseffect++;
			if (freepf_head == NULL) {             //�ڴ��޿���ҳ��
				min = 32767;
				for (int j = 0; j < total_vp; j++) {  //�ҳ��ڴ����time����Сֵ
					if (min > pl[j].time && pl[j].pfn != INVALID)  // ��ѯҳ��
					{
						min = pl[j].time;
						minj = j;  // �����ڴ���
					}
				}
				freepf_head = &pfc[pl[minj].pfn];   //�ڳ�һ����Ԫ����Ӧ���ڴ�飩
				pl[minj].pfn = INVALID;
				pl[minj].time = -1;
				freepf_head->next = NULL;
			}
			pl[page[i]].pfn = freepf_head->pfn;   //�п���ҳ��,��Ϊ��Ч���ڴ��ţ�
			pl[page[i]].time = present_time;
			freepf_head = freepf_head->next;      //����һ��free ҳ��
		}
		else {
			pl[page[i]].time = present_time;        //����������ʱ��
		}
		present_time++;
	}
	printf("LRU:%6.4f\n", 1 - diseffect / 320.0);
	return 0;
}