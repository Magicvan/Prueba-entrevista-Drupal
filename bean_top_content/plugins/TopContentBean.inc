<?php
/**
 * @file
 * Listing bean plugin.
 */

class TopContentBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(
        'records_shown' => FALSE,
      ),
    );
    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Set size record to load on bean'),
    ); 
    
    if (!$records_shown = $bean->settings['records_shown']) {
      $records_shown = 5;
    }
    $form['settings']['records_shown'] = array(
      '#type' => 'textfield',
      '#title' => t('Records shown'),
      '#size' => 5,
      '#default_value' => $records_shown,
    );
    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $night = date("h:i", strtotime("22:00"));
    $day = date("h:i", strtotime("08:00"));
    $current = date("h:i");
    $content = t("No content tracked.");
    if ($current > $day && $current < $night){
      //TODO: add the param in this view to limit the number results by settings 'records_shown' field.
      $content = views_embed_view('popular_content_oglivyone', 'todaysday');
    }else{
      $content = views_embed_view('popular_content_oglivyone', 'todaysnight');
    }
    return $content;
  }
}