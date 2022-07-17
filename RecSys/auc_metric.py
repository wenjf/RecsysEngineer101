"""
    author=wenjf
    date=2022/07/17
    推荐系统常用工具函数python实现, WPI
"""
import typing

def main():
    pass

class PredItem():
    """

    """
    def __init__(self, label, predict_score) -> None:
        self._label = label
        self._score = predict_score


class AucSet():
    """
        预留的公共父类接口
    """
    def __init__(self) -> None:
        pass
    
    
    
def cal_binary_classification_auc(pred_results: typing.List[PredItem]) -> float:
    """
        根据打分结果计算auc
    """
    # 原地排序，升序
    """
        希望怎么计算: 
        1. 对于每个分数，知道前面分数比自己小的neg有多少个
        2. 和自己分数相等的neg有多少个
        
    """
    
    
    pred_results.sort(key=lambda x: x._score, reverse=False)
    cnt_pos, cnt_neg = 0, 0
    pair_cnt = 0.
    # 不同的分数才计算一遍
    cur = 0
    while cur < len(pred_results):
        next_idx = cur
        same_pos, same_neg = 0, 0 # 每一个不同的分数计算一次
        while next_idx < len(pred_results) and pred_results[next_idx]._score == pred_results[cur]._score:
            if pred_results[next_idx]._label > 0.5:
                same_pos += 1
            else:
                same_neg += 1
            next_idx += 1
        pair_cnt += (cnt_neg * same_pos) # 比这个分数低的负样本有 cnt_neg 个，这个分数的正样本有 same_pos 个，一共能构成 cnt_neg * same_pos 个正序对
        pair_cnt += (same_neg * same_pos * 0.5) # 等于这个分数的负样本有 same_neg个， ，一共能构成 same_neg个， * same_pos * 0.5 个正序对
        cnt_pos += same_pos # 更新累积正样本数量
        cnt_neg += same_neg # 更新累积负样本数量
        cur = next_idx # 更新要处理的分数的下标
    
    total_pair = cnt_pos * cnt_neg
    final_auc = pair_cnt / total_pair
    return final_auc
        
        
        