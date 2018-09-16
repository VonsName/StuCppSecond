#pragma once
typedef void LinkedQueue;


//�������е���ʽ�洢
LinkedQueue* createLinkedQueue();


//���ٶ���
void destroyLinkedQueue(LinkedQueue* queue);

//��ն���
void clearLinkedQueue(LinkedQueue* queue);

//�����
void* insertLinkedQueue(LinkedQueue* queue, void *item);

//������
void* popLinkedQueue(LinkedQueue* queue);

//���ض���ͷ��Ԫ��
void* leftLinkedQueue(LinkedQueue* queue);

//���г���
int lenLinkedQueue(LinkedQueue* queue);

