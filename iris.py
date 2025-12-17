'''
    任务:鸢尾花的识别
'''
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import GridSearchCV
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
from sklearn.tree import plot_tree

DATA_FILE = '/Users/a0000/iris/data/iris.csv'

SPECIES = {'setosa': 0,      # 山鸢尾
           'versicolor': 1,  # 变色鸢尾
           'virginica': 2}   # 维吉利亚鸢尾

# 使用特征列
FEAT_COLS = ['sepal_length', 'sepal_width', 'petal_length', 'petal_width']
def main():
    # 读取数据集
    iris_data = pd.read_csv(DATA_FILE)
    iris_data['Label'] = iris_data['species'].map(SPECIES)
    # 获取数据特征
    X=iris_data[FEAT_COLS].values
    # 获取数据标签
    y=iris_data['Label'].values
    # 划分数据集
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=1/3, random_state=10, stratify=y)
    # 数据标准化
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)

    model_dict={'knn':(KNeighborsClassifier(),{'n_neighbors':[5,15,25],'p':[1,2]}),
                'svm':(SVC(),{'C':[1e-3,1,1e2]}),
                'log_reg': (LogisticRegression(max_iter=500),{'C':[1e-3,1,1e2]}),
                'dt': (DecisionTreeClassifier(),{'max_depth':[3,6,9]})}

    # 测试并打印精度
    for model_name, (model, param_grid) in model_dict.items():
        #训练模型
        clf = GridSearchCV(model, param_grid, cv=5)
        clf.fit(X_train, y_train)
        best_model = clf.best_estimator_
        #验证模型
        accuracy = best_model.score(X_test, y_test)
        #打印精度
        print(f'{model_name} (最佳参数: {clf.best_params_}) 精确度：{accuracy * 100:.2f}%')
        #树的图像生成
        if model_name == 'dt':
            plt.figure(figsize=(12, 8))
            plot_tree(best_model, feature_names=FEAT_COLS, class_names=list(SPECIES.keys()), filled=True)
            plt.savefig('decision_tree.png')
            print("Decision Tree plot saved as decision_tree.png")

if __name__ == '__main__':
     main()