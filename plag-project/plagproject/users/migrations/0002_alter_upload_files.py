# Generated by Django 3.2.6 on 2021-08-20 11:57

from django.db import migrations, models
import users.models


class Migration(migrations.Migration):

    dependencies = [
        ('users', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='upload',
            name='files',
            field=models.FileField(blank=True, null=True, upload_to=users.models.upload_name),
        ),
    ]
