/*
* ImagiNet Compiler 4.0.359.65534
* Copyright (c) 2019- [Imagimob AB], All Rights Reserved.
* 
* Generated at 08/24/2023 15:11:34 UTC. Any changes will be lost.
* 
* Model ID  2e2823c6-156d-418c-9cca-f945f11cbcd4
* 
* Memory    Size                      Efficiency
* Buffers   3800 bytes (RAM)          84 %
* State     808 bytes (RAM)           100 %
* Readonly  26456 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.10.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-balanced-1
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | standing
* 2           | running
* 3           | walking
* 4           | sitting
* 5           | jumping
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [50,3]          float      dequeue
*    window_shape = [50,3]
*    stride = 30
*    buffer_multiplier = 2
* Input Layer                    [50,3]          float      dequeue
*    shape = [50,3]
* Convolution 1D                 [25,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,16]
* Batch Normalization            [25,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [25,16]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Convolution 1D                 [25,16]         float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Batch Normalization            [25,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [25,16]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [12,16]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [12,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Convolution 1D                 [12,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [12,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [12,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [6,32]          float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [6]             float      dequeue
*    units = 6
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,6]
*    bias = float[6]
* Activation                     [6]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[6].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[3].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 95.259 %
* (F1S) F1 Score 94.592 %
* 
* Name of class                                            (unlabelled)          jumping          running          sitting         standing          walking
* (TP) True Positive or Correct Positive Prediction                 111              723              915             1638             1355             1245
* (FN) False Negative or Incorrect Negative Prediction              202               52                1                0               43                0
* (FP) False Positive or Incorrect Positive Prediction                6               74               61                3                9              145
* (TN) True Negative or Correct Negative Prediction                5966             5436             5308             4644             4878             4895
* (TPR) True Positive Rate or Sensitivity, Recall               35.46 %          93.29 %          99.89 %         100.00 %          96.92 %         100.00 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.90 %          98.66 %          98.86 %          99.94 %          99.82 %          97.12 %
* (PPV) Positive Predictive Value or Precision                  94.87 %          90.72 %          93.75 %          99.82 %          99.34 %          89.57 %
* (NPV) Negative Predictive Value                               96.73 %          99.05 %          99.98 %         100.00 %          99.13 %         100.00 %
* (FNR) False Negative Rate or Miss Rate                        64.54 %           6.71 %           0.11 %           0.00 %           3.08 %           0.00 %
* (FPR) False Positive Rate or Fall-Out                          0.10 %           1.34 %           1.14 %           0.06 %           0.18 %           2.88 %
* (FDR) False Discovery Rate                                     5.13 %           9.28 %           6.25 %           0.18 %           0.66 %          10.43 %
* (FOR) False Omission Rate                                      3.27 %           0.95 %           0.02 %           0.00 %           0.87 %           0.00 %
* (F1S) F1 Score                                                51.63 %          91.98 %          96.72 %          99.91 %          98.12 %          94.50 %
*/


#define IMAI_TEST_AVG_ACC 0.9525855210819412 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9459237856667039 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 111, FN: 202, FP: 6, TN: 5966, TPR: 0.3546325878594, TNR: 0.9989953114534, PPV: 0.9487179487179, NPV: 0.9672503242542, FNR: 0.6453674121405, FPR: 0.0010046885465, FDR: 0.0512820512820, FOR: 0.0327496757457, F1S: 0.5162790697674, }, \
 {name: "standing", TP: 1355, FN: 43, FP: 9, TN: 4878, TPR: 0.9692417739628, TNR: 0.9981583793738, PPV: 0.9934017595307, NPV: 0.9912619386303, FNR: 0.0307582260371, FPR: 0.0018416206261, FDR: 0.0065982404692, FOR: 0.0087380613696, F1S: 0.9811730629978, }, \
 {name: "running", TP: 915, FN: 1, FP: 61, TN: 5308, TPR: 0.9989082969432, TNR: 0.9886384801639, PPV: 0.9375, NPV: 0.9998116406102, FNR: 0.0010917030567, FPR: 0.0113615198360, FDR: 0.0625, FOR: 0.0001883593897, F1S: 0.9672304439746, }, \
 {name: "walking", TP: 1245, FN: 0, FP: 145, TN: 4895, TPR: 1, TNR: 0.9712301587301, PPV: 0.8956834532374, NPV: 1, FNR: 0, FPR: 0.0287698412698, FDR: 0.1043165467625, FOR: 0, F1S: 0.9449715370018, }, \
 {name: "sitting", TP: 1638, FN: 0, FP: 3, TN: 4644, TPR: 1, TNR: 0.9993544222078, PPV: 0.9981718464351, NPV: 1, FNR: 0, FPR: 0.0006455777921, FDR: 0.0018281535648, FOR: 0, F1S: 0.9990850869167, }, \
 {name: "jumping", TP: 723, FN: 52, FP: 74, TN: 5436, TPR: 0.9329032258064, TNR: 0.9865698729582, PPV: 0.9071518193224, NPV: 0.9905247813411, FNR: 0.0670967741935, FPR: 0.0134301270417, FDR: 0.0928481806775, FOR: 0.0094752186588, F1S: 0.9198473282442, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 95.307 %
* (F1S) F1 Score 94.902 %
* 
* Name of class                                            (unlabelled)          jumping          running          sitting         standing          walking
* (TP) True Positive or Correct Positive Prediction                 215             2460             2845             4419             4149             3987
* (FN) False Negative or Incorrect Negative Prediction              387               84              127                0               82              210
* (FP) False Positive or Incorrect Positive Prediction               61              133              224               50              190              232
* (TN) True Negative or Correct Negative Prediction               18302            16288            15769            14496            14544            14536
* (TPR) True Positive Rate or Sensitivity, Recall               35.71 %          96.70 %          95.73 %         100.00 %          98.06 %          95.00 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.67 %          99.19 %          98.60 %          99.66 %          98.71 %          98.43 %
* (PPV) Positive Predictive Value or Precision                  77.90 %          94.87 %          92.70 %          98.88 %          95.62 %          94.50 %
* (NPV) Negative Predictive Value                               97.93 %          99.49 %          99.20 %         100.00 %          99.44 %          98.58 %
* (FNR) False Negative Rate or Miss Rate                        64.29 %           3.30 %           4.27 %           0.00 %           1.94 %           5.00 %
* (FPR) False Positive Rate or Fall-Out                          0.33 %           0.81 %           1.40 %           0.34 %           1.29 %           1.57 %
* (FDR) False Discovery Rate                                    22.10 %           5.13 %           7.30 %           1.12 %           4.38 %           5.50 %
* (FOR) False Omission Rate                                      2.07 %           0.51 %           0.80 %           0.00 %           0.56 %           1.42 %
* (F1S) F1 Score                                                48.97 %          95.78 %          94.19 %          99.44 %          96.83 %          94.75 %
*/


#define IMAI_TRAIN_AVG_ACC 0.953071447403111 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9490173650037186 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 215, FN: 387, FP: 61, TN: 18302, TPR: 0.3571428571428, TNR: 0.9966781027065, PPV: 0.7789855072463, NPV: 0.9792926320295, FNR: 0.6428571428571, FPR: 0.0033218972934, FDR: 0.2210144927536, FOR: 0.0207073679704, F1S: 0.4897494305239, }, \
 {name: "standing", TP: 4149, FN: 82, FP: 190, TN: 14544, TPR: 0.9806192389506, TNR: 0.9871046558979, PPV: 0.9562111085503, NPV: 0.9943935457404, FNR: 0.0193807610493, FPR: 0.0128953441020, FDR: 0.0437888914496, FOR: 0.0056064542595, F1S: 0.9682613768961, }, \
 {name: "running", TP: 2845, FN: 127, FP: 224, TN: 15769, TPR: 0.9572678331090, TNR: 0.9859938723191, PPV: 0.9270120560443, NPV: 0.9920105686965, FNR: 0.0427321668909, FPR: 0.0140061276808, FDR: 0.0729879439556, FOR: 0.0079894313034, F1S: 0.9418970369144, }, \
 {name: "walking", TP: 3987, FN: 210, FP: 232, TN: 14536, TPR: 0.9499642601858, TNR: 0.9842903575297, PPV: 0.9450106660346, NPV: 0.9857588498575, FNR: 0.0500357398141, FPR: 0.0157096424702, FDR: 0.0549893339653, FOR: 0.0142411501424, F1S: 0.9474809885931, }, \
 {name: "sitting", TP: 4419, FN: 0, FP: 50, TN: 14496, TPR: 1, TNR: 0.9965626289014, PPV: 0.9888118147236, NPV: 1, FNR: 0, FPR: 0.0034373710985, FDR: 0.0111881852763, FOR: 0, F1S: 0.9943744374437, }, \
 {name: "jumping", TP: 2460, FN: 84, FP: 133, TN: 16288, TPR: 0.9669811320754, TNR: 0.9919006150660, PPV: 0.9487080601619, NPV: 0.9948692890300, FNR: 0.0330188679245, FPR: 0.0080993849339, FDR: 0.0512919398380, FOR: 0.0051307109699, F1S: 0.9577574459801, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 85.288 %
* (F1S) F1 Score 84.736 %
* 
* Name of class                                            (unlabelled)          jumping          running          sitting         standing          walking
* (TP) True Positive or Correct Positive Prediction                 191              591              903             1155             1260             1442
* (FN) False Negative or Incorrect Negative Prediction              259              144                3              385               97               68
* (FP) False Positive or Incorrect Positive Prediction               34              114              149                7              453              199
* (TN) True Negative or Correct Negative Prediction                6014             5649             5443             4951             4688             4789
* (TPR) True Positive Rate or Sensitivity, Recall               42.44 %          80.41 %          99.67 %          75.00 %          92.85 %          95.50 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.44 %          98.02 %          97.34 %          99.86 %          91.19 %          96.01 %
* (PPV) Positive Predictive Value or Precision                  84.89 %          83.83 %          85.84 %          99.40 %          73.56 %          87.87 %
* (NPV) Negative Predictive Value                               95.87 %          97.51 %          99.94 %          92.78 %          97.97 %          98.60 %
* (FNR) False Negative Rate or Miss Rate                        57.56 %          19.59 %           0.33 %          25.00 %           7.15 %           4.50 %
* (FPR) False Positive Rate or Fall-Out                          0.56 %           1.98 %           2.66 %           0.14 %           8.81 %           3.99 %
* (FDR) False Discovery Rate                                    15.11 %          16.17 %          14.16 %           0.60 %          26.44 %          12.13 %
* (FOR) False Omission Rate                                      4.13 %           2.49 %           0.06 %           7.22 %           2.03 %           1.40 %
* (F1S) F1 Score                                                56.59 %          82.08 %          92.24 %          85.49 %          82.08 %          91.53 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8528778085564789 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.847363169948259 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 191, FN: 259, FP: 34, TN: 6014, TPR: 0.4244444444444, TNR: 0.9943783068783, PPV: 0.8488888888888, NPV: 0.9587119400605, FNR: 0.5755555555555, FPR: 0.0056216931216, FDR: 0.1511111111111, FOR: 0.0412880599394, F1S: 0.5659259259259, }, \
 {name: "standing", TP: 1260, FN: 97, FP: 453, TN: 4688, TPR: 0.9285187914517, TNR: 0.9118848473059, PPV: 0.7355516637478, NPV: 0.9797283176593, FNR: 0.0714812085482, FPR: 0.0881151526940, FDR: 0.2644483362521, FOR: 0.0202716823406, F1S: 0.8208469055374, }, \
 {name: "running", TP: 903, FN: 3, FP: 149, TN: 5443, TPR: 0.9966887417218, TNR: 0.9733547925608, PPV: 0.8583650190114, NPV: 0.9994491369812, FNR: 0.0033112582781, FPR: 0.0266452074391, FDR: 0.1416349809885, FOR: 0.0005508630187, F1S: 0.9223697650663, }, \
 {name: "walking", TP: 1442, FN: 68, FP: 199, TN: 4789, TPR: 0.9549668874172, TNR: 0.9601042502004, PPV: 0.8787324801950, NPV: 0.9859995882231, FNR: 0.0450331125827, FPR: 0.0398957497995, FDR: 0.1212675198049, FOR: 0.0140004117768, F1S: 0.9152649952396, }, \
 {name: "sitting", TP: 1155, FN: 385, FP: 7, TN: 4951, TPR: 0.75, TNR: 0.9985881403791, PPV: 0.9939759036144, NPV: 0.9278485757121, FNR: 0.25, FPR: 0.0014118596208, FDR: 0.0060240963855, FOR: 0.0721514242878, F1S: 0.8549222797927, }, \
 {name: "jumping", TP: 591, FN: 144, FP: 114, TN: 5649, TPR: 0.8040816326530, TNR: 0.9802186361270, PPV: 0.8382978723404, NPV: 0.9751424132573, FNR: 0.1959183673469, FPR: 0.0197813638729, FDR: 0.1617021276595, FOR: 0.0248575867426, F1S: 0.8208333333333, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "standing", "running", "walking", "sitting", "jumping"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xc6, 0x23, 0x28, 0x2e, 0x6d, 0x15, 0x8c, 0x41, 0x9c, 0xca, 0xf9, 0x45, 0xf1, 0x1c, 0xbc, 0xd4}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE (0x0)
#define IMAGINET_TYPES_FLOAT32  (0x14)
#define IMAGINET_TYPES_FLOAT64  (0x18)
#define IMAGINET_TYPES_INT8 (0x21)
#define IMAGINET_TYPES_INT16    (0x22)
#define IMAGINET_TYPES_INT32    (0x24)
#define IMAGINET_TYPES_INT64    (0x28)
#define IMAGINET_TYPES_QDYN8    (0x31)
#define IMAGINET_TYPES_QDYN16   (0x32)
#define IMAGINET_TYPES_QDYN32   (0x34)

// data_in [3] (12 bytes)
#define IMAI_DATA_IN_COUNT (3)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [6] (24 bytes)
#define IMAI_DATA_OUT_COUNT (6)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (39)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
