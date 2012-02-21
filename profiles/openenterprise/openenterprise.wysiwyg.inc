<?php

/**
 * @file openenterprise.wysiwyg.inc
 * 
 * This has been split out as it was getting too long and may be reused elsewhere.
 * 
 * Install setup for:
 * Filtered HTML Text Filter
 * WYSIWYG Configuration for Filtered HTML
 * Full HTML Text Filter
 * WYSIWYG Configuration for Full HTML
 * Authenticated role permissions for Filtered HTML format
 */

function openenterprise_wysiwyg_formats() {
  // Clean out old formats
  db_delete('wysiwyg')
    ->condition('format', 'filtered_html')
    ->execute();
  db_delete('wysiwyg')
    ->condition('format', 'full_html')
    ->execute();
  
  // Filtered HTML Text Filter
  $filtered_html_format = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'weight' => 0,
    'filters' => array(
      // Caption filter
      'caption_filter' => array(
        'weight' => 20,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 0,
        'status' => 0,
      ),
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => '72',
        )
      ),
      // HTML filter.
      'filter_html' => array(
        'weight' => 1,
        'status' => 0,
        'settings' => array(
          'allowed_html' => '<a> <img> <br> <em> <p> <strong> <cite> <span> <blockquote> <ul> <ol> <li> <pre> <address> <h2> <h3> <h4> <h5> <h6>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      // WYSIWYG HTML filter.
      'wysiwyg_filter' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'valid_elements' => 'a[!href|target<_blank|title],
div[align<center?justify?left?right],
p[align<center?justify?left?right],
br,span,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd
img[!src|alt|width|height|class|typeof],
@[class|style|title]',
          'allow_comments' => 0,
          'nofollow_policy' => 'disabled',
          'style_text' => array(
            'text-align' => 'text-align',
          ),
        ),
      ),
      // Image Resize Filter.
      'image_resize_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'link' => 0,
          'link_class' => '',
          'link_rel' => '',
          'image_locations' => array(
            'local' => 'local',
            'remote' => 0,
          ),
        ),
      ),
    ),
  );
  $filtered_html_format = (object) $filtered_html_format;
  filter_format_save($filtered_html_format);

  // WYSIWYG Configuration for Filtered HTML
  $filtered_html_wysiwyg = array(
    'format' => 'filtered_html',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'justifyleft' => 1,
          'justifycenter' => 1,
          'justifyright' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'link' => 1,
          'unlink' => 1,
          'image' => 1,
          'cut' => 1,
          'copy' => 1,
          'paste' => 1,
          'removeformat' => 1,
          'inlinepopups' => 1,
        ),
        'advimage' => array(
          'advimage' => 1,
        ),
        'font' => array(
          'formatselect' => 1,
          'styleselect' => 1,
        ),
        'paste' => array(
          'pastetext' => 1,
          'pasteword' => 1,
        ),
        'captionfilter' => array(
          'captionfilter' => 1, 
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 0,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 1,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'self',
      'css_path' => '%bprofiles/openenterprise/wysiwyg_align.css,%bprofiles/openenterprise/wysiwyg_cleanup.css',
      'css_classes' => 'Align Image Right=align-right
Align Image Left=align-left',
    ),
  );
  $filtered_html_wysiwyg['settings'] = serialize($filtered_html_wysiwyg['settings']);
  drupal_write_record('wysiwyg', $filtered_html_wysiwyg);

  // Full HTML Text Filter
  $full_html_format = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'weight' => 1,
    'filters' => array(
      // Caption filter
      'caption_filter' => array(
        'weight' => 20,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 0,
        'status' => 0,
      ),
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => '72',
        )
      ),
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // HTML filter.
      'filter_html' => array(
        'weight' => 1,
        'status' => 0,
      ),
      // WYSIWYG HTML filter.
      'wysiwyg_filter' => array(
        'weight' => 1,
        'status' => 0,
        'settings' => array(
          'valid_elements' => 'a[!href|target<_blank|title],
div[align<center?justify?left?right],
p[align<center?justify?left?right],
br,span,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd
img[!src|alt|width|height|class|typeof],
@[class|style|title]',
          'allow_comments' => 0,
          'nofollow_policy' => 'disabled',
          'style_text' => array(
            'text-align' => 'text-align',
          ),
          'style_layout' => array(
            'float' => 'float',
          ),
        ),
      ),
      // Image Resize Filter.
      'image_resize_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'link' => 0,
          'link_class' => '',
          'link_rel' => '',
          'image_locations' => array(
            'local' => 'local',
            'remote' => 0,
          ),
        ),
      ),
    ),
  );
  $full_html_format = (object) $full_html_format;
  filter_format_save($full_html_format);

  // WYSIWYG Configuration for Full HTML
  $full_html_wysiwyg = array(
    'format' => 'full_html',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'justifyleft' => 1,
          'justifycenter' => 1,
          'justifyright' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'link' => 1,
          'unlink' => 1,
          'image' => 1,
          'cut' => 1,
          'copy' => 1,
          'paste' => 1,
          'removeformat' => 1,
          'inlinepopups' => 1,
        ),
        'advimage' => array(
          'advimage' => 1,
        ),
        'font' => array(
          'formatselect' => 1,
          'styleselect' => 1,
        ),
        'paste' => array(
          'pastetext' => 1,
          'pasteword' => 1,
        ),
        'captionfilter' => array(
          'captionfilter' => 1, 
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 0,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 1,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'self',
      'css_path' => '%bprofiles/openenterprise/wysiwyg_align.css,%bprofiles/openenterprise/wysiwyg_cleanup.css',
      'css_classes' => 'Align Image Right=align-right
Align Image Left=align-left',
    ),
  );
  $full_html_wysiwyg['settings'] = serialize($full_html_wysiwyg['settings']);
  drupal_write_record('wysiwyg', $full_html_wysiwyg);

  $filtered_html_permission = filter_permission_name($filtered_html_format);
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array($filtered_html_permission));  
}

function openenterprise_wysiwyg_create_image_field($type) {
  if (!field_read_field('field_inline_image', array('include_inactive' => TRUE))) {
    // Create an image field named "Image", enabled for a content type.
    $field = array(
      'field_name' => 'field_inline_image',
      'type' => 'image',
      'cardinality' => -1,
      'locked' => FALSE,
      'indexes' => array('fid' => array('fid')),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    );
    field_create_field($field);
  }

  if (!field_read_instance('node', 'field_inline_image', $type)) {
    // Set up the field instance. Many of these settings are related to the WYSIWYG setup.
    $instance = array(
      'field_name' => 'field_inline_image',
      'entity_type' => 'node',
      'label' => 'Image',
      'bundle' => $type,
      'description' => st('Upload an image to insert in this node. After selecting the image, press "Insert" to add to the page.'),
      'required' => FALSE,

      'settings' => array(
        'file_directory' => 'inline-images',  
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'alt_field' => TRUE,
        'title_field' => TRUE,
      ),

      'widget' => array(
        'type' => 'image_image',
        'settings' => array(
          'progress_indicator' => 'bar',
          'preview_image_style' => 'thumbnail',
          'filefield_sources' => array(
            'filefield_sources' => array(
              'imce' => 'imce',
              'remote' => 'remote',
              'reference' => 'reference',
              'attach' => 0,
            ),
            'source_attach' => array(
              'path' => 'file_attach',
              'absolute' => 0,
              'attach_mode' => 'copy',
            ),
            'source_reference' => array(
              'autocomplete' => 0,
            ),
          ),
          'insert' => 1,
          'insert_styles' => array(
            'image' => 'image',
            'image_large' => 'image_large',
            'image_medium' => 'image_medium',
            'image_thumbnail' => 'image_thumbnail',
            'auto' => 0,
            'link' => 0,
          ),
          'insert_default' => 'image',
          'insert_class' => 'inline',
          'insert_width' => '',
          'caption_from_title' => 1,
        ),
        'weight' => 40,
      ),
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'type' => 'hidden',
          'settings' => array(),
          'weight' => -1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'type' => 'hidden',
          'settings' => array(),
          'weight' => -1,
        ),
      ),
    );
    field_create_instance($instance);
  }
}