//
//  ATSurveyViewModel.h
//  CVSurvey
//
//  Created by Frank Schmitt on 2/23/16.
//  Copyright © 2016 Apptentive, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ATSurveyQuestion.h"

@class ATSurvey, ATInteraction, ApptentiveStyleSheet;

@protocol ATSurveyViewModelDelegate;


@interface ATSurveyViewModel : NSObject

- (instancetype)initWithInteraction:(ATInteraction *)interaction NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

// Consider making this private
@property (readonly, nonatomic) ATInteraction *interaction;
@property (readonly, nonatomic) ATSurvey *survey;
@property (readonly, nonatomic) ApptentiveStyleSheet *styleSheet;
@property (weak, nonatomic) id<ATSurveyViewModelDelegate> delegate;

@property (readonly, nonatomic) NSString *title;
@property (readonly, nonatomic) NSString *greeting;
@property (readonly, nonatomic) NSString *submitButtonText;

@property (readonly, nonatomic) BOOL showThankYou;
@property (readonly, nonatomic) NSString *thankYouText;

- (NSInteger)numberOfQuestionsInSurvey;
- (NSInteger)numberOfAnswersForQuestionAtIndex:(NSInteger)index;

- (NSString *)textOfQuestionAtIndex:(NSInteger)index;
- (NSString *)instructionTextOfQuestionAtIndex:(NSInteger)index;
- (NSString *)placeholderTextOfQuestionAtIndex:(NSInteger)index;
- (ATSurveyQuestionType)typeOfQuestionAtIndex:(NSInteger)index;

- (NSString *)textOfAnswerAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)answerAtIndexPathIsSelected:(NSIndexPath *)indexPath;
- (BOOL)answerIsValidForQuestionAtIndex:(NSInteger)index;

- (void)setText:(NSString *)text forAnswerAtIndexPath:(NSIndexPath *)indexPath;
- (void)selectAnswerAtIndexPath:(NSIndexPath *)indexPath;
- (void)deselectAnswerAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)validate:(BOOL)isSubmit;
- (void)submit;

- (void)didCancel;
- (void)didSubmit;
- (void)commitChangeAtIndexPath:(NSIndexPath *)indexPath;

@property (readonly, nonatomic) NSDictionary *answers;

@end

@protocol ATSurveyViewModelDelegate <NSObject>

- (void)viewModel:(ATSurveyViewModel *)viewModel didDeselectAnswerAtIndexPath:(NSIndexPath *)indexPath;
- (void)viewModelValidationChanged:(ATSurveyViewModel *)viewModel;

@end